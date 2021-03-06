{
    "targets": [{
        "target_name": "cctokenizer",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "cppsrc/main.cpp",
            "cppsrc/tokenizer_wrapper.cpp"            
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",            
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}