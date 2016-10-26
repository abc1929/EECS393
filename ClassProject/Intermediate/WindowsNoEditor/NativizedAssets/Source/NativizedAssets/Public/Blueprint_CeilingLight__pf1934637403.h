#pragma once
#include "Blueprint/BlueprintSupport.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/CoreUObject/Classes/Object.h"
class UStaticMeshComponent;
class USceneComponent;
class UPointLightComponent;
#include "Blueprint_CeilingLight__pf1934637403.generated.h"
UCLASS(config=Engine, Blueprintable, BlueprintType, meta=(ReplaceConverted="/Game/StarterContent/Blueprints/Blueprint_CeilingLight.Blueprint_CeilingLight_C", OverrideNativeName="Blueprint_CeilingLight_C"))
class ABlueprint_CeilingLight_C__pf1934637403 : public AActor
{
public:
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="SM_Lamp_Ceiling"))
	UStaticMeshComponent* bpv__SM_Lamp_Ceiling__pf;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="PointLight1"))
	UPointLightComponent* bpv__PointLight1__pf;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Scene1"))
	USceneComponent* bpv__Scene1__pf;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Brightness", Category="Light", OverrideNativeName="Brightness"))
	float bpv__Brightness__pf;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Color", Category="Light", OverrideNativeName="Color"))
	FLinearColor bpv__Color__pf;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Source Radius", Category="Light", OverrideNativeName="Source Radius"))
	float bpv__SourcexRadius__pfT;
	ABlueprint_CeilingLight_C__pf1934637403(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	static void __CustomDynamicClassInitialization(UDynamicClass* InDynamicClass);
	static void __StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_CommonAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", DisplayName="Construction Script", ToolTip="Construction script, the place to spawn components and do other setup.@note Name used in CreateBlueprint function@param       Location        The location.@param       Rotation        The rotation.", Category, CppFromBpEvent, OverrideNativeName="UserConstructionScript"))
	void bpf__UserConstructionScript__pf();
public:
};
