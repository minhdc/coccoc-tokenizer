#include <napi.h>
#include "../../tokenizer/tokenizer.hpp"
//#include "hello.hpp"


class TokenizerWrapper : public Napi::ObjectWrap<TokenizerWrapper>{
    
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        TokenizerWrapper(const Napi::CallbackInfo& info);   
        Napi::Number initialize(const Napi::CallbackInfo& info);
        Napi::String to_string_range(const Napi::CallbackInfo& info);
        Napi::Value get_next_token(const Napi::CallbackInfo& info);
        Napi::Value normalize_for_tokenization(const Napi::CallbackInfo& info);
        Napi::Boolean maximize(const Napi::CallbackInfo& info);

    private:
        static Napi::FunctionReference constructor;
        Napi::Value unserialize_nontone_data(const Napi::CallbackInfo& info);
        Napi::Value load_serialized_dicts(const Napi::CallbackInfo& info);

        
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