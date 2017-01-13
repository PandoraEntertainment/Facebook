
#pragma once

#include "FacebookSDKSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UFacebookSDKSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UFacebookSDKSettings(const FObjectInitializer& ObjectInitializer);
	
	// SDK Ids

	UPROPERTY(Config, EditAnywhere, Category = Parse, meta = (DisplayName = "App ID"))
	FString FBID;

	
};
