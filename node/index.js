const coccoc_tokenizer = require('./build/Release/cctokenizer.node')
let h = new coccoc_tokenizer.HelloWrapper("Minh")
console.log(coccoc_tokenizer)
console.log(h.getUserName())

module.export = coccoc_tokenizer