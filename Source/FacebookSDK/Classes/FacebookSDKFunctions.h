
#pragma once

#include "FacebookSDKFunctions.generated.h"



UCLASS(NotBlueprintable)
class UFacebookSDKFunctions : public UObject {
	GENERATED_BODY()
	
public:

#if PLATFORM_ANDROID
	static void InitJavaFunctions();
#endif

	UFUNCTION(BlueprintCallable, meta = (Keywords = "FacebookSDK "), Category = "FacebookSDK|")
	static void FacebookSDK_Login();

	UFUNCTION(BlueprintCallable, meta = (Keywords = "FacebookSDK "), Category = "FacebookSDK|")
	static void FacebookSDK_Logout();

	UFUNCTION(BlueprintCallable, meta = (Keywords = "FacebookSDK "), Category = "FacebookSDK|")
	static void FacebookSDK_AppInvite();

	UFUNCTION(BlueprintCallable, meta = (Keywords = "FacebookSDK "), Category = "FacebookSDK|")
	static void FacebookSDK_SharePhoto(FString AppName, FString Filename);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "FacebookSDK "), Category = "FacebookSDK|")
	static FString FacebookGetAccessToken();

	UFUNCTION(BlueprintPure, meta = (Keywords = "FacebookSDK "), Category = "FacebookSDK|")
	static bool FacebookIsLoggedIn();
	

};
