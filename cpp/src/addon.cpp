#include <napi.h>

#include "../include/srt_parser.h"
#include "../include/subtitle.h"

Napi::Value ParseSRT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  std::string filepath = info[0].As<Napi::String>();

  std::vector<Subtitle> subtitles = parseSRT(filepath);

  Napi::Array result = Napi::Array::New(env, subtitles.size());
  for (size_t i = 0; i < subtitles.size(); ++i) {
    Napi::Object obj = Napi::Object::New(env);
    obj.Set("start", subtitles[i].start);
    obj.Set("end", subtitles[i].end);
    obj.Set("text", subtitles[i].text);
    result.Set(i, obj);
  }

  return result;
}

Napi::Value ExportSRT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Array subtitles = info[0].As<Napi::Array>();
  std::string filepath = info[1].As<Napi::String>();

  std::vector<Subtitle> subtitleVec;
  for (size_t i = 0; i < subtitles.Length(); ++i) {
    Napi::Object obj = subtitles.Get(i).As<Napi::Object>();
    int start = obj.Get("start").As<Napi::Number>().Int32Value();
    int end = obj.Get("end").As<Napi::Number>().Int32Value();
    std::string text = obj.Get("text").As<Napi::String>();

    Subtitle subtitle(start, end, text);  // Use parameterized constructor
    subtitleVec.push_back(subtitle);
  }

  exportSRT(subtitleVec, filepath);

  return env.Null();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "parseSRT"),
              Napi::Function::New(env, ParseSRT));
  exports.Set(Napi::String::New(env, "exportSRT"),
              Napi::Function::New(env, ExportSRT));
  return exports;
}

NODE_API_MODULE(addon, Init)
