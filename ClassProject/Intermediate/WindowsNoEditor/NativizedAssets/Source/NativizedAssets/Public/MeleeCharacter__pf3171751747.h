#pragma once
#include "Blueprint/BlueprintSupport.h"
#include "ClassProject/ClassProjectCharacter.h"
#include "Runtime/CoreUObject/Classes/Object.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
class AActor;
class AFireball_C__pf1471916900;
#include "MeleeCharacter__pf3171751747.generated.h"
UCLASS(config=Game, Blueprintable, BlueprintType, meta=(ReplaceConverted="/Game/ThirdPersonCPP/Blueprints/MeleeCharacter.MeleeCharacter_C", OverrideNativeName="MeleeCharacter_C"))
class AMeleeCharacter_C__pf3171751747 : public AClassProjectCharacter
{
public:
	GENERATED_BODY()
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_GetControlRotation_ReturnValue"))
	FRotator b0l__CallFunc_GetControlRotation_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_GetForwardVector_ReturnValue"))
	FVector b0l__CallFunc_GetForwardVector_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputKeyEvent_Key"))
	FKey b0l__K2Node_InputKeyEvent_Key__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_Multiply_VectorFloat_ReturnValue"))
	FVector b0l__CallFunc_Multiply_VectorFloat_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_K2_GetActorLocation_ReturnValue"))
	FVector b0l__CallFunc_K2_GetActorLocation_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_Add_VectorVector_ReturnValue"))
	FVector b0l__CallFunc_Add_VectorVector_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_MakeTransform_ReturnValue"))
	FTransform b0l__CallFunc_MakeTransform_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue"))
	AActor* b0l__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_FinishSpawningActor_ReturnValue"))
	AFireball_C__pf1471916900* b0l__CallFunc_FinishSpawningActor_ReturnValue__pf;
	AMeleeCharacter_C__pf3171751747(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	static void __CustomDynamicClassInitialization(UDynamicClass* InDynamicClass);
	static void __StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_CommonAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	void bpf__ExecuteUbergraph_MeleeCharacter__pf_0(int32 bpp__EntryPoint__pf);
	UFUNCTION(meta=(OverrideNativeName="InpActEvt_LeftMouseButton_K2Node_InputKeyEvent_1"))
	virtual void bpf__InpActEvt_LeftMouseButton_K2Node_InputKeyEvent_1__pf(FKey bpp__Key__pf);
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", DisplayName="Construction Script", ToolTip="Construction script, the place to spawn components and do other setup.@note Name used in CreateBlueprint function@param       Location        The location.@param       Rotation        The rotation.", Category, CppFromBpEvent, OverrideNativeName="UserConstructionScript"))
	void bpf__UserConstructionScript__pf();
public:
};
