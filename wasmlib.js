// made a library to not always write/copy the same functions I always use in was
window.wasmlib = {
  // getting Cstring length in memory
  str_len: (mem, str_ptr) => {
    let len = 0;
    while (mem[str_ptr] != 0) {
      len++;
      str_ptr++;
    }
    return len;
  },
  // getting a Cstring from wasm memory
  get_str: (str_ptr) => {
    const buffer = wasm.instance.exports.memory.buffer;
    const mem = new Uint8Array(buffer);
    const len = str_len(mem, str_ptr);
    const str_bytes = new Uint8Array(buffer, str_ptr, len);
    return new TextDecoder().decode(str_bytes);
  },
  // a "working" printf in wasm that works with c printf
  printf: (str_ptr, args_ptrs) => {
    const buffer = wasm.instance.exports.memory.buffer;
    const str = get_str(str_ptr);
    let f_str = "";
    let args = [];
    let argsIndex = 0;
    for (let i = 0; i < str.length; i++) {
      if (str[i] === "%") {
        switch (str[i + 1]) {
          case "f":
            let float = new Float32Array(buffer, args_ptrs + argsIndex, 1)[0];
            args.push(float);
            f_str += float;
            argsIndex += 4;
            i += 2;
            break;
          case "d":
            let int = new Int32Array(buffer, args_ptrs + argsIndex, 1)[0];
            args.push(int);
            f_str += int;
            argsIndex += 4;
            i += 2;
            break;
          case "u":
            let uint = new Uint32Array(buffer, args_ptrs + argsIndex, 1)[0];
            args.push(uint);
            f_str += uint;
            argsIndex += 4;
            i += 2;
            break;
          case "s":
            const str_ptr = new Uint32Array(
              buffer,
              args_ptrs + argsIndex,
              1
            )[0];
            let str = get_str(str_ptr);
            args.push(str);
            f_str += str;
            argsIndex += 4;
            i += 2;
            break;
          case "i":
            let iint = new Int32Array(buffer, args_ptrs + argsIndex, 1)[0];
            args.push(iint);
            f_str += iint;
            argsIndex += 4;
            i += 2;
            break;
          case "p":
            let ptr = args_ptrs + argsIndex;
            args.push(ptr);
            f_str += ptr;
            argsIndex += 4;
            i += 2;
            break;
        }
      }
      if (str[i] != undefined) f_str += str[i];
    }
    console.log(f_str);
    // console.log(get_str(args_ptrs), new Uint32Array(buffer, args_ptrs, 1));
  },
};
