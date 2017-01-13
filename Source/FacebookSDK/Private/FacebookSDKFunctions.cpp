
#include "FacebookSDKPrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJNI.h"
#include "AndroidApplication.h"

#define INIT_JAVA_METHOD(name, signature) \
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
	check(name != NULL); \
} else { \
	check(0); \
}

#define DECLARE_JAVA_METHOD(name) \
static jmethodID name = NULL;

DECLARE_JAVA_METHOD(AndroidThunkJava_FacebookSDK_Login);
DECLARE_JAVA_METHOD(AndroidThunkJava_FacebookSDK_Logout);
DECLARE_JAVA_METHOD(AndroidThunkJava_FacebookGetAccessToken);
DECLARE_JAVA_METHOD(AndroidThunkJava_FacebookSDK_AppInvite);
DECLARE_JAVA_METHOD(AndroidThunkJava_FacebookSDK_SharePhoto);
DECLARE_JAVA_METHOD(AndroidThunkJava_FacebookSDK_isLoggedIn);



void UFacebookSDKFunctions::InitJavaFunctions()
{

	INIT_JAVA_METHOD(AndroidThunkJava_FacebookSDK_Login, "()V");
	INIT_JAVA_METHOD(AndroidThunkJava_FacebookSDK_Logout, "()V");
	INIT_JAVA_METHOD(AndroidThunkJava_FacebookGetAccessToken, "()Ljava/lang/String;");
	INIT_JAVA_METHOD(AndroidThunkJava_FacebookSDK_AppInvite, "()V");
	INIT_JAVA_METHOD(AndroidThunkJava_FacebookSDK_SharePhoto, "(Ljava/lang/String;Ljava/lang/String;)V");
	INIT_JAVA_METHOD(AndroidThunkJava_FacebookSDK_isLoggedIn, "()Z");
	
}
#undef DECLARE_JAVA_METHOD
#undef INIT_JAVA_METHOD


extern "C" void Java_com_epicgames_ue4_GameActivity_nativeFacebookOnLoginComplete(JNIEnv* jenv, jobject thiz)
{
	FGraphEventRef EnterBackgroundTask = FFunctionGraphTask::CreateAndDispatchWhenReady([&]()
	{
		UFacebookSDKComponent::onFacebookLoginCompletedDelegate.Broadcast();


	}, TStatId(), NULL, ENamedThreads::GameThread);
}

extern "C" void Java_com_epicgames_ue4_GameActivity_nativeFacebookOnLoginCancelled(JNIEnv* jenv, jobject thiz)
{
	UFacebookSDKComponent::onFacebookLoginCancelledDelegate.Broadcast();
}

extern "C" void Java_com_epicgames_ue4_GameActivity_nativeFacebookOnLoginError(JNIEnv* jenv, jobject thiz, jstring error)
{
	FString Error;

	const char* charsError = jenv->GetStringUTFChars(error, 0);
	Error = FString(UTF8_TO_TCHAR(charsError));
	jenv->ReleaseStringUTFChars(error, charsError);

	UFacebookSDKComponent::onFacebookLoginErrorDelegate.Broadcast(Error);
}


#endif





bool UFacebookSDKFunctions:: FacebookIsLoggedIn() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{


		bool ret = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_FacebookSDK_isLoggedIn);



		UE_LOG(LogAndroid, Warning, TEXT("I found the java method FacebookSDKisLoggedIn\n"));

		return ret;

	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif

	return false;

}


void UFacebookSDKFunctions::FacebookSDK_Login() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{


		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_FacebookSDK_Login);



		UE_LOG(LogAndroid, Warning, TEXT("I found the java method FacebookSDKLogin\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif

}

void UFacebookSDKFunctions::FacebookSDK_Logout() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{


		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_FacebookSDK_Logout);



		UE_LOG(LogAndroid, Warning, TEXT("I found the java method FacebookSDKLogout\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif

}


void UFacebookSDKFunctions::FacebookSDK_AppInvite() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{


		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_FacebookSDK_AppInvite);



		UE_LOG(LogAndroid, Warning, TEXT("I found the java method FacebookSDK_AppInvite\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif

}

void UFacebookSDKFunctions::FacebookSDK_SharePhoto(FString AppName, FString Filename) {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring AppNameArg = Env->NewStringUTF(TCHAR_TO_UTF8(*AppName));
		jstring FilenameArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Filename));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_FacebookSDK_SharePhoto, AppNameArg, FilenameArg);

		Env->DeleteLocalRef(AppNameArg);
		Env->DeleteLocalRef(FilenameArg);

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method FacebookSDK_SharePhoto()\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif

}


FString UFacebookSDKFunctions::FacebookGetAccessToken()
{
	FString Result;

#if PLATFORM_IOS

#elif PLATFORM_ANDROID

	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{

		jstring AccessToken = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_FacebookGetAccessToken);

		const char *s = Env->GetStringUTFChars(AccessToken, 0);
		Result = FString(UTF8_TO_TCHAR(s));

		Env->ReleaseStringUTFChars(AccessToken, s);
	}
#endif

	return Result;
}