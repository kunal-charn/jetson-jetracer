#ifndef UNTITLED1__VISIBILITY_CONTROL_H_
#define UNTITLED1__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define UNTITLED1_EXPORT __attribute__ ((dllexport))
    #define UNTITLED1_IMPORT __attribute__ ((dllimport))
  #else
    #define UNTITLED1_EXPORT __declspec(dllexport)
    #define UNTITLED1_IMPORT __declspec(dllimport)
  #endif
  #ifdef UNTITLED1_BUILDING_LIBRARY
    #define UNTITLED1_PUBLIC UNTITLED1_EXPORT
  #else
    #define UNTITLED1_PUBLIC UNTITLED1_IMPORT
  #endif
  #define UNTITLED1_PUBLIC_TYPE UNTITLED1_PUBLIC
  #define UNTITLED1_LOCAL
#else
  #define UNTITLED1_EXPORT __attribute__ ((visibility("default")))
  #define UNTITLED1_IMPORT
  #if __GNUC__ >= 4
    #define UNTITLED1_PUBLIC __attribute__ ((visibility("default")))
    #define UNTITLED1_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define UNTITLED1_PUBLIC
    #define UNTITLED1_LOCAL
  #endif
  #define UNTITLED1_PUBLIC_TYPE
#endif
#endif  // UNTITLED1__VISIBILITY_CONTROL_H_
// Generated 21-Oct-2022 15:20:51
// Copyright 2019-2020 The MathWorks, Inc.
