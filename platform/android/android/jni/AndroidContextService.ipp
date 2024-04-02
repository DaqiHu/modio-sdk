/*
 *  Copyright (C) 2021 mod.io Pty Ltd. <https://mod.io>
 *
 *  This file is part of the mod.io SDK.
 *
 *  Distributed under the MIT License. (See accompanying file LICENSE or
 *   view online at <https://github.com/modio/modio-sdk/blob/main/LICENSE>)
 *
 */

#ifdef MODIO_SEPARATE_COMPILATION
	#include "jni/AndroidContextService.h"
#endif

#include "jni/JavaClassWrapperModio.h"
#include <inttypes.h>
#include <jni.h>
#include "jni/JavaHelpers.h"

#define JNI_CURRENT_VERSION JNI_VERSION_1_6

namespace Modio
{
	namespace Detail
	{
		AndroidContextService& AndroidContextService::Get()
		{
			static AndroidContextService Instance;
			return Instance;
		}

		void AndroidContextService::InternalInitializeJNI(JavaVM* InJavaVM, jobject InClassLoader)
		{
			JNIEnv* Env = nullptr;
			InJavaVM->GetEnv((void**) &Env, JNI_CURRENT_VERSION);
			JVM = InJavaVM;

			ClassLoader = InClassLoader;

			auto EnvClass = Modio::Detail::NewScopedJavaObject(Env, Env->FindClass("android/os/Environment"));

			// Find the ClassLoader.findClass method
			jclass classLoaderClass = Env->FindClass("java/lang/ClassLoader");
			FindClassMethod = Env->GetMethodID(classLoaderClass, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");

		}

		void AndroidContextService::InitializeJNI(JavaVM* InJavaVM, jobject InClassLoader)
		{
			auto& AndroidContextService = Modio::Detail::AndroidContextService::Get();

			AndroidContextService.InternalInitializeJNI(InJavaVM, InClassLoader);
		}

		JNIEnv* AndroidContextService::GetJavaEnv()
		{
		    JNIEnv* Env = nullptr;
			jint GetEnvResult = JVM->GetEnv((void**) &Env, JNI_CURRENT_VERSION);

			if (GetEnvResult == JNI_EDETACHED)
			{
				jint AttachResult = JVM->AttachCurrentThread(&Env, NULL);

				if (AttachResult == JNI_ERR)
				{
					return nullptr;
				}
			} else if (GetEnvResult != JNI_OK) 
			{
				return nullptr;
			}

			return Env;
		}

		void AndroidContextService::SetGlobalActivity(jobject InActivityObject)
		{
			ActivityObject = InActivityObject;
		};

		void AndroidContextService::InitializeAndroid()
		{
			JavaClassModio = new JavaClassWrapperModio(ActivityObject);
		}

	} // namespace Detail
} // namespace Modio
