#include <napi.h>
#include "tokenizer_wrapper.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports){
    return HelloWrapper::Init(env,exports);
    //return ;
}

NODE_API_MODULE(cctokenizer, InitAll)