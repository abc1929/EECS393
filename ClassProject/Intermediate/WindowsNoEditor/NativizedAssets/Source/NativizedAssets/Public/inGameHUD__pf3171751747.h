#pragma once
#include "Blueprint/BlueprintSupport.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
class AMage_C__pf3171751747;
class UProgressBar;
class UEditableTextBox;
class ACharacter;
#include "inGameHUD__pf3171751747.generated.h"
UCLASS(config=Engine, Blueprintable, BlueprintType, meta=(ReplaceConverted="/Game/ThirdPersonCPP/Blueprints/inGameHUD.inGameHUD_C", OverrideNativeName="inGameHUD_C"))
class UinGameHUD_C__pf3171751747 : public UUserWidget
{
public:
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Transient, meta=(DisplayName="EditableTextBox_0", Category="inGameHUD", OverrideNativeName="EditableTextBox_0"))
	UEditableTextBox* bpv__EditableTextBox_0__pf;
	UPROPERTY(BlueprintReadWrite, Transient, meta=(DisplayName="EditableTextBox_1", Category="inGameHUD", OverrideNativeName="EditableTextBox_1"))
	UEditableTextBox* bpv__EditableTextBox_1__pf;
	UPROPERTY(BlueprintReadWrite, Transient, meta=(DisplayName="HPBar", Category="inGameHUD", OverrideNativeName="HPBar"))
	UProgressBar* bpv__HPBar__pf;
	UPROPERTY(BlueprintReadWrite, Transient, meta=(DisplayName="StamBar", Category="inGameHUD", OverrideNativeName="StamBar"))
	UProgressBar* bpv__StamBar__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Mage", Category="默认", OverrideNativeName="Mage"))
	AMage_C__pf3171751747* bpv__Mage__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_GetPlayerCharacter_ReturnValue"))
	ACharacter* b0l__CallFunc_GetPlayerCharacter_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_DynamicCast_AsMage"))
	AMage_C__pf3171751747* b0l__K2Node_DynamicCast_AsMage__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_DynamicCast_bSuccess"))
	bool b0l__K2Node_DynamicCast_bSuccess__pf;
	UinGameHUD_C__pf3171751747(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	static void __CustomDynamicClassInitialization(UDynamicClass* InDynamicClass);
	static void __StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_CommonAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	void bpf__ExecuteUbergraph_inGameHUD__pf_0(int32 bpp__EntryPoint__pf);
	UFUNCTION(BlueprintCosmetic, meta=(Category="User Interface", Keywords="Begin Play", ToolTip="Called after the underlying slate widget is constructed.  Depending on how the slate object is usedthis event may be called multiple times due to adding and removing from the hierarchy.", CppFromBpEvent, OverrideNativeName="Construct"))
	void bpf__Construct__pf();
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(Category, OverrideNativeName="Get_HPBar_Percent_0"))
	virtual float  bpf__Get_HPBar_Percent_0__pf();
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(Category, OverrideNativeName="Get_StamBar_Percent_0"))
	virtual float  bpf__Get_StamBar_Percent_0__pf();
public:
	virtual void GetSlotNames(TArray<FName>& SlotNames) const override;
	virtual void PreSave(const class ITargetPlatform* TargetPlatform) override;
	virtual void CustomNativeInitilize() override;
};
