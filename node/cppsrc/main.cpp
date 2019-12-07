#include <napi.h>
#include "tokenizer_wrapper.h"

//function that init the native wrapper 
Napi::Object InitAll(Napi::Env env, Napi::Object exports){
    return TokenizerWrapper::Init(env,exports);
    //return ;
}

NODE_API_MODULE(cctokenizer, InitAll)