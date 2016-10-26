#pragma once
#include "Blueprint/BlueprintSupport.h"
#include "ClassProject/ClassProjectCharacter.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/CoreUObject/Classes/Object.h"
class AFireball_C__pf1471916900;
class AActor;
class UinGameHUD_C__pf3171751747;
class APlayerController;
#include "Mage__pf3171751747.generated.h"
UCLASS(config=Game, Blueprintable, BlueprintType, meta=(ReplaceConverted="/Game/ThirdPersonCPP/Blueprints/Mage.Mage_C", OverrideNativeName="Mage_C"))
class AMage_C__pf3171751747 : public AClassProjectCharacter
{
public:
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Health", Category="Default", ClampMin="-50", ClampMax="100", UIMin="0", UIMax="100", tooltip="HP", OverrideNativeName="Health"))
	float bpv__Health__pf;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Stamina", Category="Default", tooltip="Stamina", UIMin="0", UIMax="100", ClampMin="0", ClampMax="100", OverrideNativeName="Stamina"))
	float bpv__Stamina__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_K2_SetTimer_ReturnValue"))
	FTimerHandle b0l__CallFunc_K2_SetTimer_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputKeyEvent_Key"))
	FKey b0l__K2Node_InputKeyEvent_Key__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputKeyEvent_Key2"))
	FKey b0l__K2Node_InputKeyEvent_Key2__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_K2_GetActorLocation_ReturnValue"))
	FVector b0l__CallFunc_K2_GetActorLocation_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_GetControlRotation_ReturnValue"))
	FRotator b0l__CallFunc_GetControlRotation_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_GetPlayerController_ReturnValue"))
	APlayerController* b0l__CallFunc_GetPlayerController_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_GetForwardVector_ReturnValue"))
	FVector b0l__CallFunc_GetForwardVector_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_Create_ReturnValue"))
	UinGameHUD_C__pf3171751747* b0l__CallFunc_Create_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_Multiply_VectorFloat_ReturnValue"))
	FVector b0l__CallFunc_Multiply_VectorFloat_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_Add_VectorVector_ReturnValue"))
	FVector b0l__CallFunc_Add_VectorVector_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputKeyEvent_Key3"))
	FKey b0l__K2Node_InputKeyEvent_Key3__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_MakeTransform_ReturnValue"))
	FTransform b0l__CallFunc_MakeTransform_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue"))
	AActor* b0l__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_FinishSpawningActor_ReturnValue"))
	AFireball_C__pf1471916900* b0l__CallFunc_FinishSpawningActor_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_Less_FloatFloat_ReturnValue"))
	bool b0l__CallFunc_Less_FloatFloat_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_Event_DeltaSeconds"))
	float b0l__K2Node_Event_DeltaSeconds__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_K2_SetTimer_ReturnValue2"))
	FTimerHandle b0l__CallFunc_K2_SetTimer_ReturnValue2__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputKeyEvent_Key4"))
	FKey b0l__K2Node_InputKeyEvent_Key4__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_LessEqual_FloatFloat_ReturnValue"))
	bool b0l__CallFunc_LessEqual_FloatFloat_ReturnValue__pf;
	AMage_C__pf3171751747(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	static void __CustomDynamicClassInitialization(UDynamicClass* InDynamicClass);
	static void __StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_CommonAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	void bpf__ExecuteUbergraph_Mage__pf_0(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_Mage__pf_1(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_Mage__pf_2(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_Mage__pf_3(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_Mage__pf_4(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_Mage__pf_5(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_Mage__pf_6(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_Mage__pf_7(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_Mage__pf_8(int32 bpp__EntryPoint__pf);
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="PlayerOutForceField"))
	virtual void bpf__PlayerOutForceField__pf();
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="PlayerInForceField"))
	virtual void bpf__PlayerInForceField__pf();
	virtual void OnJumped_Implementation() override;
	UFUNCTION(meta=(DisplayName="Tick", ToolTip="Event called every frame", CppFromBpEvent, OverrideNativeName="ReceiveTick"))
	void bpf__ReceiveTick__pf(float bpp__DeltaSeconds__pf);
	UFUNCTION(meta=(DisplayName="BeginPlay", ToolTip="Event when play begins for this actor.", CppFromBpEvent, OverrideNativeName="ReceiveBeginPlay"))
	void bpf__ReceiveBeginPlay__pf();
	UFUNCTION(meta=(OverrideNativeName="InpActEvt_T_K2Node_InputKeyEvent_12"))
	virtual void bpf__InpActEvt_T_K2Node_InputKeyEvent_12__pf(FKey bpp__Key__pf);
	UFUNCTION(meta=(OverrideNativeName="InpActEvt_G_K2Node_InputKeyEvent_13"))
	virtual void bpf__InpActEvt_G_K2Node_InputKeyEvent_13__pf(FKey bpp__Key__pf);
	UFUNCTION(meta=(OverrideNativeName="InpActEvt_F_K2Node_InputKeyEvent_14"))
	virtual void bpf__InpActEvt_F_K2Node_InputKeyEvent_14__pf(FKey bpp__Key__pf);
	UFUNCTION(meta=(OverrideNativeName="InpActEvt_LeftMouseButton_K2Node_InputKeyEvent_15"))
	virtual void bpf__InpActEvt_LeftMouseButton_K2Node_InputKeyEvent_15__pf(FKey bpp__Key__pf);
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", DisplayName="Construction Script", ToolTip="Construction script, the place to spawn components and do other setup.@note Name used in CreateBlueprint function@param       Location        The location.@param       Rotation        The rotation.", Category, CppFromBpEvent, OverrideNativeName="UserConstructionScript"))
	void bpf__UserConstructionScript__pf();
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="TestDamage"))
	virtual void bpf__TestDamage__pf();
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="GetHealthPercentage"))
	virtual void bpf__GetHealthPercentage__pf(/*out*/ float& bpp__Perc__pf);
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="StaminaRegeneration"))
	virtual void bpf__StaminaRegeneration__pf();
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="TestStamina"))
	virtual void bpf__TestStamina__pf();
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="GetStamPercentage"))
	virtual void bpf__GetStamPercentage__pf(/*out*/ float& bpp__Perc__pf);
	virtual bool  CanJumpInternal_Implementation() const override;
	bool  bpf__CanJumpInternal__pf_Inner_0();
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="TakeForceFieldDamage"))
	virtual void bpf__TakeForceFieldDamage__pf();
public:
};
