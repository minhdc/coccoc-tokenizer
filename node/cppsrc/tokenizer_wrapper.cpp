#include "tokenizer_wrapper.h"

Napi::FunctionReference TokenizerWrapper::constructor;

Napi::Object TokenizerWrapper::Init(Napi::Env env, Napi::Object exports){
    Napi::HandleScope scope(env);

    
    Napi::Function func = DefineClass(env, "TokenizerWrapper",{
        InstanceMethod("segment",&TokenizerWrapper::segment),
        InstanceMethod("segment_original",&TokenizerWrapper::segment_original),
    });
    

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("segment",func);
    exports.Set("segment_original",func);
    return exports;
}

TokenizerWrapper::TokenizerWrapper(const Napi::CallbackInfo& info) : Napi::ObjectWrap<TokenizerWrapper>(info){
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    //Tokenizer t = Tokenizer::instance().initialize(info[0].As<Napi::String>(),info[1].As<Napi::String>());;
     this->tokenizer_ = new Tokenizer();
     this->tokenizer_->instance().initialize(info[0].As<Napi::String>(),info[1].As<Napi::String>());
}



Napi::Value TokenizerWrapper::segment(const Napi::CallbackInfo& info){
    std::vector<FullToken> answer =
     this
        ->tokenizer_
        ->segment(info[0].As<Napi::String>(),info[1].As<Napi::Boolean>(), info[2].As<Napi::Number>());
    return Napi::Array::From(info.Env(),answer);
}



Napi::Value TokenizerWrapper::segment_original(const Napi::CallbackInfo& info){
    return Napi::String::New(info.Env(),"hello");
}



/*
HelloWrapper::HelloWrapper(const Napi::CallbackInfo& info) : Napi::ObjectWrap<HelloWrapper>(info){
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    Napi::String value = info[0].As<Napi::String>();
    this -> hello_ = new Hello(value.ToString());
}

Napi::Value HelloWrapper::getUserName(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    string userName = this -> hello_ -> getUserName();
    return Napi::String::New(env,userName);
}


Napi::FunctionReference HelloWrapper::constructor;

Napi::Object HelloWrapper::Init(Napi::Env env, Napi::Object exports){
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "HelloWrapper",{
        InstanceMethod("getUserName",&HelloWrapper::getUserName)
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("HelloWrapper",func);
    return exports;
}

HelloWrapper::HelloWrapper(const Napi::CallbackInfo& info) : Napi::ObjectWrap<HelloWrapper>(info){
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    Napi::String value = info[0].As<Napi::String>();
    this -> hello_ = new Hello(value.ToString());
}

Napi::Value HelloWrapper::getUserName(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    string userName = this -> hello_ -> getUserName();
    return Napi::String::New(env,userName);
}
*/