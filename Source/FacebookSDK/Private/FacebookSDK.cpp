
#include "FacebookSDKPrivatePCH.h"
#include "FacebookSDKSettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogFacebookSDK);

#define LOCTEXT_NAMESPACE "FacebookSDK"

class FFacebookSDK : public IFacebookSDK
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FFacebookSDK, FacebookSDK )

void FFacebookSDK::StartupModule()
{
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "FacebookSDK",
										 LOCTEXT("RuntimeSettingsName", "FacebookSDK"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the FacebookSDK plugin"),
										 GetMutableDefault<UFacebookSDKSettings>()
										 );
	}

#if PLATFORM_ANDROID
	UFacebookSDKFunctions::InitJavaFunctions();
#endif
}


void FFacebookSDK::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
