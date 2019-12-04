#include "tokenizer_wrapper.h"

Napi::FunctionReference TokenizerWrapper::constructor;

Napi::Object TokenizerWrapper::Init(Napi::Env env, Napi::Object exports){
    Napi::HandleScope scope(env);

    /*
    Napi::Function func = DefineClass(env, "HelloWrapper",{
        InstanceMethod("getUserName",&TokenizerWrapper::getUserName)
    });
    */

    //constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    //exports.Set("HelloWrapper",func);
    return exports;
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