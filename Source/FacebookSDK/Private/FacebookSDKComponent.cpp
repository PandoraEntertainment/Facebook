
#include "FacebookSDKPrivatePCH.h"

void UFacebookSDKComponent::OnRegister()
{
	Super::OnRegister();
	

	UFacebookSDKComponent::onFacebookLoginCompletedDelegate.AddUObject(this, &UFacebookSDKComponent::onFacebookLoginCompleted_Handler);

	UFacebookSDKComponent::onFacebookLoginCancelledDelegate.AddUObject(this, &UFacebookSDKComponent::onFacebookLoginCancelled_Handler);

	UFacebookSDKComponent::onFacebookLoginErrorDelegate.AddUObject(this, &UFacebookSDKComponent::onFacebookLoginError_Handler);

}

void UFacebookSDKComponent::OnUnregister()
{
	Super::OnUnregister();
	

	UFacebookSDKComponent::onFacebookLoginCompletedDelegate.RemoveAll(this);

	UFacebookSDKComponent::onFacebookLoginCancelledDelegate.RemoveAll(this);

	UFacebookSDKComponent::onFacebookLoginErrorDelegate.RemoveAll(this);
}

UFacebookSDKComponent::FFacebookSDKonFacebookLoginCompletedDelegate UFacebookSDKComponent::onFacebookLoginCompletedDelegate;

UFacebookSDKComponent::FFacebookSDKonFacebookLoginCancelledDelegate UFacebookSDKComponent::onFacebookLoginCancelledDelegate;

UFacebookSDKComponent::FFacebookSDKonFacebookLoginErrorDelegate UFacebookSDKComponent::onFacebookLoginErrorDelegate;
