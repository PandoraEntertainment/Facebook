
#pragma once

#include "FacebookSDKFunctions.h"
#include "FacebookSDKComponent.generated.h"

UCLASS(ClassGroup=Advertising, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UFacebookSDKComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:

	
	DECLARE_MULTICAST_DELEGATE(FFacebookSDKonFacebookLoginCompletedDelegate);

	static FFacebookSDKonFacebookLoginCompletedDelegate onFacebookLoginCompletedDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFacebookSDKonFacebookLoginCompletedDelegateDynDelegate);

	UPROPERTY(BlueprintAssignable)
	FFacebookSDKonFacebookLoginCompletedDelegateDynDelegate onFacebookLoginCompleted;


	DECLARE_MULTICAST_DELEGATE(FFacebookSDKonFacebookLoginCancelledDelegate);

	static FFacebookSDKonFacebookLoginCancelledDelegate onFacebookLoginCancelledDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFacebookSDKonFacebookLoginCancelledDynDelegate);

	UPROPERTY(BlueprintAssignable)
	FFacebookSDKonFacebookLoginCancelledDynDelegate onFacebookLoginCancelled;


	DECLARE_MULTICAST_DELEGATE_OneParam(FFacebookSDKonFacebookLoginErrorDelegate, FString);

	static FFacebookSDKonFacebookLoginErrorDelegate onFacebookLoginErrorDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFacebookSDKonFacebookLoginErrorDynDelegate, FString, Error);

	UPROPERTY(BlueprintAssignable)
	FFacebookSDKonFacebookLoginErrorDynDelegate onFacebookLoginError;


	
	void OnRegister() override;
	void OnUnregister() override;
	
private:	
	

	void onFacebookLoginCompleted_Handler() { onFacebookLoginCompleted.Broadcast(); }
	void onFacebookLoginCancelled_Handler() { onFacebookLoginCancelled.Broadcast(); }
	void onFacebookLoginError_Handler(FString Error) { onFacebookLoginError.Broadcast(Error); }

	

};
