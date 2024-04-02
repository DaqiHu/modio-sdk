#ifdef MODIO_SEPARATE_COMPILATION
	#include "jni/JavaClassWrapperModio.h"
#endif
#include "jni/AndroidContextService.h"
#include "modio/core/ModioLogger.h"
#include "jni/JavaClassWrapper.h"
#include "jni/JavaHelpers.h"

namespace Modio
{
	namespace Detail
	{
		JavaClassWrapperModio::JavaClassWrapperModio(jobject Activity)
			:
		JavaClassWrapper("com/modio/modiosdk/Modio", "(Landroid/app/Activity;)V", Activity)
		{
			JNIEnv* Env = Modio::Detail::AndroidContextService::Get().GetJavaEnv();
			
			GetCertificatePathMethodId = Env->GetMethodID(Class, "getCertificatePath", "()Ljava/lang/String;");
			GetStoragePathMethodId = Env->GetMethodID(Class, "getStorageDirectory", "()Ljava/lang/String;");
		} 

		std::string JavaClassWrapperModio::GetCertificatePath()
		{
			JNIEnv* Env = Modio::Detail::AndroidContextService::Get().GetJavaEnv();

			auto RetVal = Env->CallObjectMethod(Object, GetCertificatePathMethodId);

			auto Result = Modio::Detail::JavaHelpers::StringFromLocalRef(Env, (jstring) RetVal);

			return Result;
		}

		std::string JavaClassWrapperModio::GetStoragePath()
		{
			JNIEnv* Env = Modio::Detail::AndroidContextService::Get().GetJavaEnv();

			auto RetVal = Env->CallObjectMethod(Object, GetStoragePathMethodId);

			auto Result = Modio::Detail::JavaHelpers::StringFromLocalRef(Env, (jstring) RetVal);

			return Result;
		}


	}
}
