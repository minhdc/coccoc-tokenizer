#include <napi.h>
#include "../../tokenizer/tokenizer.hpp"
//#include "../../tokenizer/auxiliary/vn_lang_tool.hpp"
//#include "hello.hpp"


class TokenizerWrapper : public Napi::ObjectWrap<TokenizerWrapper>{
    
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        TokenizerWrapper(const Napi::CallbackInfo& info);   
        Napi::Value segment(const Napi::CallbackInfo& info);
        //Napi::Value segment_original(const Napi::CallbackInfo& info);
        //Napi::Value initialize(const Napi::CallbackInfo& info);
    private:
        static Napi::FunctionReference constructor;
        Tokenizer *tokenizer_;

        
};
/*
class HelloWrapper : public Napi::ObjectWrap<HelloWrapper>{
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);        
        HelloWrapper(const Napi::CallbackInfo& info);
    private:
        static Napi::FunctionReference constructor;
        Napi::Value getUserName(const Napi::CallbackInfo& info);
        Hello *hello_;        
};*/