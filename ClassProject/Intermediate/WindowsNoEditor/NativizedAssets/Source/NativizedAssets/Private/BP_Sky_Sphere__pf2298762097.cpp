#include "NativizedAssets.h"
#include "BP_Sky_Sphere__pf2298762097.h"
#include "GeneratedCodeHelpers.h"
#include "Runtime/Engine/Classes/Engine/SimpleConstructionScript.h"
#include "Runtime/Engine/Classes/Engine/SCS_Node.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Materials/Material.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/Engine/EngineBaseTypes.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphPin.h"
#include "Runtime/Engine/Classes/Engine/AssetUserData.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_AssetUserData.h"
#include "Runtime/Engine/Classes/GameFramework/PhysicsVolume.h"
#include "Runtime/Engine/Classes/GameFramework/Volume.h"
#include "Runtime/Engine/Classes/Engine/Brush.h"
#include "Runtime/Engine/Classes/Components/BrushComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/TouchInterface.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Engine/Classes/Engine/Texture.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineReplStructs.h"
#include "Runtime/Engine/Classes/Camera/CameraTypes.h"
#include "Runtime/Engine/Classes/Camera/CameraAnim.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroup.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrack.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInst.h"
#include "Runtime/Engine/Classes/Camera/CameraShake.h"
#include "Runtime/Engine/Classes/Engine/Scene.h"
#include "Runtime/Engine/Classes/Engine/TextureCube.h"
#include "Runtime/Engine/Classes/Camera/CameraAnimInst.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstMove.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackMove.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroupInst.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"
#include "Runtime/Engine/Classes/Particles/EmitterCameraLensEffectBase.h"
#include "Runtime/Engine/Classes/Particles/Emitter.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterial.h"
#include "Runtime/Engine/Classes/Vehicles/TireType.h"
#include "Runtime/Engine/Classes/Engine/DataAsset.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterialPropertyBase.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsSettingsEnums.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/Materials/MaterialInterface.h"
#include "Runtime/Engine/Classes/Engine/SubsurfaceProfile.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpression.h"
#include "Runtime/Engine/Classes/Engine/BlendableInterface.h"
#include "Runtime/Engine/Public/ParticleHelper.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SkinnedMeshComponent.h"
#include "Runtime/Engine/Classes/Components/MeshComponent.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMesh.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsAsset.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetup.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodyInstance.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetupEnums.h"
#include "Runtime/Engine/Classes/PhysicsEngine/AggregateGeom.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConvexElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ShapeElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphylElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BoxElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphereElem.h"
#include "Runtime/Engine/Classes/Animation/Skeleton.h"
#include "Runtime/Engine/Classes/Animation/BlendProfile.h"
#include "Runtime/Engine/Classes/Animation/SmartName.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshSocket.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_CollisionDataProvider.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "Runtime/Engine/Classes/Animation/AnimationAsset.h"
#include "Runtime/Engine/Classes/Animation/AnimMetaData.h"
#include "Runtime/Engine/Classes/Animation/AnimSequenceBase.h"
#include "Runtime/Engine/Public/Animation/AnimCurveTypes.h"
#include "Runtime/Engine/Classes/Curves/RichCurve.h"
#include "Runtime/Engine/Classes/Curves/IndexedCurve.h"
#include "Runtime/Engine/Classes/Curves/KeyHandle.h"
#include "Runtime/Engine/Public/Animation/AnimTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimLinkableElement.h"
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "Runtime/Engine/Classes/Animation/AnimCompositeBase.h"
#include "Runtime/Engine/Public/AlphaBlend.h"
#include "Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "Runtime/Engine/Classes/Curves/CurveBase.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystem.h"
#include "Runtime/Engine/Classes/Particles/ParticleEmitter.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstance.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceBasePropertyOverrides.h"
#include "Runtime/Engine/Classes/Engine/Font.h"
#include "Runtime/SlateCore/Public/Fonts/CompositeFont.h"
#include "Runtime/SlateCore/Public/Fonts/FontBulkData.h"
#include "Runtime/Engine/Classes/Engine/FontImportOptions.h"
#include "Runtime/SlateCore/Public/Fonts/FontProviderInterface.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier_CameraShake.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerState.h"
#include "Runtime/Engine/Classes/GameFramework/Info.h"
#include "Runtime/Engine/Classes/GameFramework/LocalMessage.h"
#include "Runtime/Engine/Classes/GameFramework/EngineMessage.h"
#include "Runtime/Engine/Classes/GameFramework/ForceFeedbackEffect.h"
#include "Runtime/Engine/Classes/Sound/SoundBase.h"
#include "Runtime/Engine/Classes/Sound/SoundAttenuation.h"
#include "Runtime/Engine/Classes/Sound/SoundConcurrency.h"
#include "Runtime/Engine/Classes/Sound/SoundClass.h"
#include "Runtime/Engine/Classes/Sound/SoundMix.h"
#include "Runtime/Engine/Classes/GameFramework/HUD.h"
#include "Runtime/Engine/Classes/GameFramework/DebugTextInfo.h"
#include "Runtime/Engine/Classes/Engine/Canvas.h"
#include "Runtime/Engine/Classes/Debug/ReporterGraph.h"
#include "Runtime/Engine/Classes/Debug/ReporterBase.h"
#include "Runtime/Engine/Classes/Engine/NetSerialization.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawn.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPawn.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Components/ShapeComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAreas/NavArea.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationTypes.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAreas/NavArea_Obstacle.h"
#include "Runtime/Engine/Classes/GameFramework/PawnMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/NavMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/MovementComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationData.h"
#include "Runtime/Engine/Classes/AI/Navigation/RecastNavMesh.h"
#include "Runtime/Engine/Classes/GameFramework/FloatingPawnMovement.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskResource.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h"
#include "Runtime/AIModule/Classes/Perception/AISense.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionSystem.h"
#include "Runtime/AIModule/Classes/Perception/AISenseEvent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig.h"
#include "Runtime/AIModule/Classes/Navigation/PathFollowingComponent.h"
#include "Runtime/AIModule/Classes/AIResourceInterface.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavFilters/NavigationQueryFilter.h"
#include "Runtime/GameplayTasks/Classes/GameplayTask.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardData.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "Runtime/AIModule/Classes/BrainComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTCompositeNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTNode.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskOwnerInterface.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTService.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTAuxiliaryNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTDecorator.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeTypes.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTTaskNode.h"
#include "Runtime/AIModule/Classes/AITypes.h"
#include "Runtime/GameplayTasks/Classes/GameplayTasksComponent.h"
#include "Runtime/AIModule/Classes/Actions/PawnActionsComponent.h"
#include "Runtime/AIModule/Classes/Actions/PawnAction.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionListenerInterface.h"
#include "Runtime/AIModule/Classes/GenericTeamAgentInterface.h"
#include "Runtime/Engine/Public/VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawnMovement.h"
#include "Runtime/Engine/Classes/Engine/LatentActionManager.h"
#include "Runtime/Engine/Classes/Haptics/HapticFeedbackEffect_Base.h"
#include "Runtime/Engine/Classes/Engine/NetConnection.h"
#include "Runtime/Engine/Classes/Engine/Player.h"
#include "Runtime/Engine/Classes/Engine/Channel.h"
#include "Runtime/Engine/Classes/Engine/NetDriver.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Engine/ChildConnection.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"
#include "Runtime/Engine/Classes/GameFramework/CheatManager.h"
#include "Runtime/Engine/Classes/Engine/DebugCameraController.h"
#include "Runtime/Engine/Classes/Components/DrawFrustumComponent.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstDirector.h"
#include "Runtime/Engine/Classes/GameFramework/DamageType.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/RootMotionSource.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationAvoidanceTypes.h"
#include "Runtime/Engine/Public/AI/RVOAvoidanceInterface.h"
#include "Runtime/Engine/Classes/Interfaces/NetworkPredictionInterface.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAgentInterface.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavRelevantInterface.h"
#include "Runtime/Engine/Classes/Components/ChildActorComponent.h"
#include "BP_Sky_Sphere__pf2298762097.h"
#include "Runtime/Engine/Classes/Curves/CurveLinearColor.h"
#include "Runtime/Engine/Classes/Engine/DirectionalLight.h"
#include "Runtime/Engine/Classes/Engine/Light.h"
#include "Runtime/Engine/Classes/Components/LightComponent.h"
#include "Runtime/Engine/Classes/Components/LightComponentBase.h"
#include "Runtime/Engine/Classes/Engine/TextureLightProfile.h"
#include "Runtime/Engine/Classes/Components/DirectionalLightComponent.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
ABP_Sky_Sphere_C__pf2298762097::ABP_Sky_Sphere_C__pf2298762097(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	if(HasAnyFlags(RF_ClassDefaultObject) && (ABP_Sky_Sphere_C__pf2298762097::StaticClass() == GetClass()))
	{
		ABP_Sky_Sphere_C__pf2298762097::__CustomDynamicClassInitialization(CastChecked<UDynamicClass>(GetClass()));
	}
	
	bpv__Base__pf = CreateDefaultSubobject<USceneComponent>(TEXT("Base"));
	bpv__SkyxSpherexmesh__pfTT = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sky Sphere mesh"));
	RootComponent = bpv__Base__pf;
	bpv__Base__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__Base__pf->Mobility = EComponentMobility::Type::Static;
	bpv__SkyxSpherexmesh__pfTT->CreationMethod = EComponentCreationMethod::Native;
	bpv__SkyxSpherexmesh__pfTT->AttachToComponent(bpv__Base__pf, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__SkyxSpherexmesh__pfTT->BodyInstance.SetCollisionProfileName(FName(TEXT("NoCollision")));
	bpv__SkyxSpherexmesh__pfTT->BodyInstance.bAutoWeld = false;
	static TWeakObjectPtr<UProperty> __Local__1{};
	const UProperty* __Local__0 = __Local__1.Get();
	if (nullptr == __Local__0)
	{
		__Local__0 = (FBodyInstance::StaticStruct())->FindPropertyByName(FName(TEXT("MassInKgOverride")));
		check(__Local__0);
		__Local__1 = __Local__0;
	}
	auto& __Local__2 = (*(__Local__0->ContainerPtrToValuePtr<float >(&(bpv__SkyxSpherexmesh__pfTT->BodyInstance), 0)));
	__Local__2 = 0.000000f;
	bpv__SkyxSpherexmesh__pfTT->StaticMesh = CastChecked<UStaticMesh>(CastChecked<UDynamicClass>(ABP_Sky_Sphere_C__pf2298762097::StaticClass())->UsedAssets[0], ECastCheckedType::NullAllowed);
	bpv__SkyxSpherexmesh__pfTT->OverrideMaterials = TArray<UMaterialInterface*> ();
	bpv__SkyxSpherexmesh__pfTT->OverrideMaterials.Reserve(1);
	bpv__SkyxSpherexmesh__pfTT->OverrideMaterials.Add(CastChecked<UMaterialInterface>(CastChecked<UDynamicClass>(ABP_Sky_Sphere_C__pf2298762097::StaticClass())->UsedAssets[1], ECastCheckedType::NullAllowed));
	bpv__SkyxSpherexmesh__pfTT->bGenerateOverlapEvents = false;
	bpv__SkyxSpherexmesh__pfTT->bReceivesDecals = false;
	bpv__SkyxSpherexmesh__pfTT->CastShadow = false;
	bpv__SkyxSpherexmesh__pfTT->bAffectDynamicIndirectLighting = false;
	bpv__SkyxSpherexmesh__pfTT->bCastDynamicShadow = false;
	bpv__SkyxSpherexmesh__pfTT->bCastStaticShadow = false;
	bpv__SkyxSpherexmesh__pfTT->bAbsoluteRotation = true;
	bpv__SkyxSpherexmesh__pfTT->RelativeScale3D = FVector(400.000000, 400.000000, 400.000000);
	bpv__SkyxSpherexmesh__pfTT->Mobility = EComponentMobility::Type::Static;
	static TWeakObjectPtr<UProperty> __Local__4{};
	const UProperty* __Local__3 = __Local__4.Get();
	if (nullptr == __Local__3)
	{
		__Local__3 = (UActorComponent::StaticClass())->FindPropertyByName(FName(TEXT("bCanEverAffectNavigation")));
		check(__Local__3);
		__Local__4 = __Local__3;
	}
	(((UBoolProperty*)__Local__3)->SetPropertyValue_InContainer((bpv__SkyxSpherexmesh__pfTT), false, 0));
	if(!bpv__SkyxSpherexmesh__pfTT->IsTemplate())
	{
		bpv__SkyxSpherexmesh__pfTT->BodyInstance.FixupData(bpv__SkyxSpherexmesh__pfTT);
	}
	bpv__Skyxmaterial__pfT = nullptr;
	bpv__Refreshxmaterial__pfT = false;
	bpv__Directionalxlightxactor__pfTT = nullptr;
	bpv__Colorsxdeterminedxbyxsunxposition__pfTTTT = true;
	bpv__Sunxheight__pfT = 0.000000f;
	bpv__Sunxbrightness__pfT = 50.000000f;
	bpv__HorizonxFalloff__pfT = 3.000000f;
	bpv__ZenithxColor__pfT = FLinearColor(0.034046, 0.109247, 0.295000, 1.000000);
	bpv__Horizonxcolor__pfT = FLinearColor(1.979559, 2.586644, 3.000000, 1.000000);
	bpv__Cloudxcolor__pfT = FLinearColor(0.855778, 0.919020, 1.000000, 1.000000);
	bpv__OverallxColor__pfT = FLinearColor(1.000000, 1.000000, 1.000000, 1.000000);
	bpv__Cloudxspeed__pfT = 1.000000f;
	bpv__Cloudxopacity__pfT = 0.700000f;
	bpv__Starsxbrightness__pfT = 0.100000f;
	bpv__Horizonxcolorxcurve__pfTT = CastChecked<UCurveLinearColor>(CastChecked<UDynamicClass>(ABP_Sky_Sphere_C__pf2298762097::StaticClass())->UsedAssets[2], ECastCheckedType::NullAllowed);
	bpv__Zenithxcolorxcurve__pfTT = CastChecked<UCurveLinearColor>(CastChecked<UDynamicClass>(ABP_Sky_Sphere_C__pf2298762097::StaticClass())->UsedAssets[3], ECastCheckedType::NullAllowed);
	bpv__Cloudxcolorxcurve__pfTT = CastChecked<UCurveLinearColor>(CastChecked<UDynamicClass>(ABP_Sky_Sphere_C__pf2298762097::StaticClass())->UsedAssets[4], ECastCheckedType::NullAllowed);
	bEnableAutoLODGeneration = false;
}
void ABP_Sky_Sphere_C__pf2298762097::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
	if(bpv__Base__pf)
	{
		bpv__Base__pf->CreationMethod = EComponentCreationMethod::Native;
	}
	if(bpv__SkyxSpherexmesh__pfTT)
	{
		bpv__SkyxSpherexmesh__pfTT->CreationMethod = EComponentCreationMethod::Native;
	}
}
void ABP_Sky_Sphere_C__pf2298762097::__CustomDynamicClassInitialization(UDynamicClass* InDynamicClass)
{
	ensure(0 == InDynamicClass->ReferencedConvertedFields.Num());
	ensure(0 == InDynamicClass->MiscConvertedSubobjects.Num());
	ensure(0 == InDynamicClass->DynamicBindingObjects.Num());
	ensure(0 == InDynamicClass->ComponentTemplates.Num());
	ensure(0 == InDynamicClass->Timelines.Num());
	ensure(nullptr == InDynamicClass->AnimClassImplementation);
	InDynamicClass->AssembleReferenceTokenStream();
	FConvertedBlueprintsDependencies::FillUsedAssetsInDynamicClass(InDynamicClass, &__StaticDependencies_DirectlyUsedAssets);
}
void ABP_Sky_Sphere_C__pf2298762097::bpf__UserConstructionScript__pf()
{
	UMaterialInstanceDynamic* bpv__CallFunc_CreateDynamicMaterialInstance_ReturnValue__pf{};
	float bpv__CallFunc_Abs_ReturnValue__pf{};
	FLinearColor bpv__CallFunc_GetLinearColorValue_ReturnValue__pf(EForceInit::ForceInit);
	float bpv__CallFunc_Lerp_ReturnValue__pf{};
	bool bpv__CallFunc_Less_FloatFloat_ReturnValue__pf{};
	float bpv__CallFunc_Abs_ReturnValue2__pf{};
	float bpv__CallFunc_SelectFloat_ReturnValue__pf{};
	float bpv__CallFunc_MapRangeUnclamped_ReturnValue__pf{};
	FRotator bpv__CallFunc_K2_GetActorRotation_ReturnValue__pf(EForceInit::ForceInit);
	float bpv__CallFunc_BreakRotator_Roll__pf{};
	float bpv__CallFunc_BreakRotator_Pitch__pf{};
	float bpv__CallFunc_BreakRotator_Yaw__pf{};
	FRotator bpv__CallFunc_K2_GetActorRotation_ReturnValue2__pf(EForceInit::ForceInit);
	FRotator bpv__CallFunc_MakeRotator_ReturnValue__pf(EForceInit::ForceInit);
	float bpv__CallFunc_BreakRotator_Roll2__pf{};
	float bpv__CallFunc_BreakRotator_Pitch2__pf{};
	float bpv__CallFunc_BreakRotator_Yaw2__pf{};
	FVector bpv__CallFunc_Conv_RotatorToVector_ReturnValue__pf(EForceInit::ForceInit);
	float bpv__CallFunc_MapRangeUnclamped_ReturnValue2__pf{};
	FLinearColor bpv__CallFunc_Conv_VectorToLinearColor_ReturnValue__pf(EForceInit::ForceInit);
	FLinearColor bpv__CallFunc_GetLinearColorValue_ReturnValue2__pf(EForceInit::ForceInit);
	FLinearColor bpv__CallFunc_GetLinearColorValue_ReturnValue3__pf(EForceInit::ForceInit);
	float bpv__CallFunc_Add_FloatFloat_ReturnValue__pf{};
	float bpv__CallFunc_FClamp_ReturnValue__pf{};
	FLinearColor bpv__CallFunc_LinearColorLerp_ReturnValue__pf(EForceInit::ForceInit);
	FLinearColor bpv__CallFunc_Conv_ColorToLinearColor_ReturnValue__pf(EForceInit::ForceInit);
	bool bpv__CallFunc_IsValid_ReturnValue__pf{};
	FRotator bpv__CallFunc_K2_GetActorRotation_ReturnValue3__pf(EForceInit::ForceInit);
	FVector bpv__CallFunc_Conv_RotatorToVector_ReturnValue2__pf(EForceInit::ForceInit);
	FLinearColor bpv__CallFunc_Conv_VectorToLinearColor_ReturnValue2__pf(EForceInit::ForceInit);
	int32 CurrentState = 1;
	do
	{
		switch( CurrentState )
		{
		case 1:
			{
				if(IsValid(bpv__SkyxSpherexmesh__pfTT))
				{
					bpv__CallFunc_CreateDynamicMaterialInstance_ReturnValue__pf = bpv__SkyxSpherexmesh__pfTT->CreateDynamicMaterialInstance(0, CastChecked<UMaterialInterface>(CastChecked<UDynamicClass>(ABP_Sky_Sphere_C__pf2298762097::StaticClass())->UsedAssets[1], ECastCheckedType::NullAllowed));
				}
			}
		case 2:
			{
				bpv__Skyxmaterial__pfT = bpv__CallFunc_CreateDynamicMaterialInstance_ReturnValue__pf;
			}
		case 3:
			{
				if (!bpv__Refreshxmaterial__pfT)
				{
					CurrentState = 4;
					break;
				}
			}
		case 4:
			{
				bpv__Refreshxmaterial__pfT = false;
			}
		case 5:
			{
				bpv__CallFunc_IsValid_ReturnValue__pf = UKismetSystemLibrary::IsValid(bpv__Directionalxlightxactor__pfTT);
				if (!bpv__CallFunc_IsValid_ReturnValue__pf)
				{
					CurrentState = 19;
					break;
				}
			}
		case 6:
			{
				if(IsValid(bpv__Directionalxlightxactor__pfTT))
				{
					bpv__CallFunc_K2_GetActorRotation_ReturnValue3__pf = bpv__Directionalxlightxactor__pfTT->K2_GetActorRotation();
				}
				bpv__CallFunc_Conv_RotatorToVector_ReturnValue2__pf = UKismetMathLibrary::Conv_RotatorToVector(bpv__CallFunc_K2_GetActorRotation_ReturnValue3__pf);
				bpv__CallFunc_Conv_VectorToLinearColor_ReturnValue2__pf = UKismetMathLibrary::Conv_VectorToLinearColor(bpv__CallFunc_Conv_RotatorToVector_ReturnValue2__pf);
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Light direction")), bpv__CallFunc_Conv_VectorToLinearColor_ReturnValue2__pf);
				}
			}
		case 7:
			{
				FColor  __Local__5 = FColor(0,0,0,255);
				bpv__CallFunc_Conv_ColorToLinearColor_ReturnValue__pf = UKismetMathLibrary::Conv_ColorToLinearColor(((IsValid(bpv__Directionalxlightxactor__pfTT) && IsValid(bpv__Directionalxlightxactor__pfTT->LightComponent)) ? (bpv__Directionalxlightxactor__pfTT->LightComponent->LightColor) : (__Local__5)));
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Sun color")), bpv__CallFunc_Conv_ColorToLinearColor_ReturnValue__pf);
				}
			}
		case 8:
			{
				if(IsValid(bpv__Directionalxlightxactor__pfTT))
				{
					bpv__CallFunc_K2_GetActorRotation_ReturnValue2__pf = bpv__Directionalxlightxactor__pfTT->K2_GetActorRotation();
				}
				UKismetMathLibrary::BreakRotator(bpv__CallFunc_K2_GetActorRotation_ReturnValue2__pf, /*out*/ bpv__CallFunc_BreakRotator_Roll2__pf, /*out*/ bpv__CallFunc_BreakRotator_Pitch2__pf, /*out*/ bpv__CallFunc_BreakRotator_Yaw2__pf);
				bpv__CallFunc_MapRangeUnclamped_ReturnValue2__pf = UKismetMathLibrary::MapRangeUnclamped(bpv__CallFunc_BreakRotator_Pitch2__pf, 0.000000, -90.000000, 0.000000, 1.000000);
				bpv__Sunxheight__pfT = bpv__CallFunc_MapRangeUnclamped_ReturnValue2__pf;
			}
		case 9:
			{
				if (!bpv__Colorsxdeterminedxbyxsunxposition__pfTTTT)
				{
					CurrentState = 21;
					break;
				}
			}
		case 10:
			{
				if(IsValid(bpv__Horizonxcolorxcurve__pfTT))
				{
					bpv__CallFunc_GetLinearColorValue_ReturnValue3__pf = bpv__Horizonxcolorxcurve__pfTT->GetLinearColorValue(bpv__Sunxheight__pfT);
				}
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Horizon color")), bpv__CallFunc_GetLinearColorValue_ReturnValue3__pf);
				}
			}
		case 11:
			{
				if(IsValid(bpv__Zenithxcolorxcurve__pfTT))
				{
					bpv__CallFunc_GetLinearColorValue_ReturnValue2__pf = bpv__Zenithxcolorxcurve__pfTT->GetLinearColorValue(bpv__Sunxheight__pfT);
				}
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Zenith color")), bpv__CallFunc_GetLinearColorValue_ReturnValue2__pf);
				}
			}
		case 12:
			{
				if(IsValid(bpv__Cloudxcolorxcurve__pfTT))
				{
					bpv__CallFunc_GetLinearColorValue_ReturnValue__pf = bpv__Cloudxcolorxcurve__pfTT->GetLinearColorValue(bpv__Sunxheight__pfT);
				}
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Cloud color")), bpv__CallFunc_GetLinearColorValue_ReturnValue__pf);
				}
			}
		case 13:
			{
				bpv__CallFunc_Abs_ReturnValue__pf = UKismetMathLibrary::Abs(bpv__Sunxheight__pfT);
				bpv__CallFunc_Lerp_ReturnValue__pf = UKismetMathLibrary::Lerp(3.000000, 7.000000, bpv__CallFunc_Abs_ReturnValue__pf);
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetScalarParameterValue(FName(TEXT("Horizon falloff")), bpv__CallFunc_Lerp_ReturnValue__pf);
				}
			}
		case 14:
			{
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetScalarParameterValue(FName(TEXT("Cloud speed")), bpv__Cloudxspeed__pfT);
				}
			}
		case 15:
			{
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetScalarParameterValue(FName(TEXT("Sun brightness")), bpv__Sunxbrightness__pfT);
				}
			}
		case 16:
			{
				bpv__CallFunc_Less_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Less_FloatFloat(bpv__Sunxheight__pfT, 0.000000);
				bpv__CallFunc_Abs_ReturnValue2__pf = UKismetMathLibrary::Abs(bpv__Sunxheight__pfT);
				bpv__CallFunc_SelectFloat_ReturnValue__pf = UKismetMathLibrary::SelectFloat(bpv__CallFunc_Abs_ReturnValue2__pf, 0.000000, bpv__CallFunc_Less_FloatFloat_ReturnValue__pf);
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetScalarParameterValue(FName(TEXT("Sun height")), bpv__CallFunc_SelectFloat_ReturnValue__pf);
				}
			}
		case 17:
			{
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetScalarParameterValue(FName(TEXT("Cloud opacity")), bpv__Cloudxopacity__pfT);
				}
			}
		case 18:
			{
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetScalarParameterValue(FName(TEXT("Stars brightness")), bpv__Starsxbrightness__pfT);
				}
				CurrentState = -1;
				break;
			}
		case 19:
			{
				bpv__CallFunc_MapRangeUnclamped_ReturnValue__pf = UKismetMathLibrary::MapRangeUnclamped(bpv__Sunxheight__pfT, -1.000000, 1.000000, 90.000000, -90.000000);
				bpv__CallFunc_K2_GetActorRotation_ReturnValue__pf = K2_GetActorRotation();
				UKismetMathLibrary::BreakRotator(bpv__CallFunc_K2_GetActorRotation_ReturnValue__pf, /*out*/ bpv__CallFunc_BreakRotator_Roll__pf, /*out*/ bpv__CallFunc_BreakRotator_Pitch__pf, /*out*/ bpv__CallFunc_BreakRotator_Yaw__pf);
				bpv__CallFunc_MakeRotator_ReturnValue__pf = UKismetMathLibrary::MakeRotator(0.000000, bpv__CallFunc_MapRangeUnclamped_ReturnValue__pf, bpv__CallFunc_BreakRotator_Yaw__pf);
				bpv__CallFunc_Conv_RotatorToVector_ReturnValue__pf = UKismetMathLibrary::Conv_RotatorToVector(bpv__CallFunc_MakeRotator_ReturnValue__pf);
				bpv__CallFunc_Conv_VectorToLinearColor_ReturnValue__pf = UKismetMathLibrary::Conv_VectorToLinearColor(bpv__CallFunc_Conv_RotatorToVector_ReturnValue__pf);
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Light direction")), bpv__CallFunc_Conv_VectorToLinearColor_ReturnValue__pf);
				}
			}
		case 20:
			{
				bpv__CallFunc_Add_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Add_FloatFloat(bpv__Sunxheight__pfT, 0.200000);
				bpv__CallFunc_FClamp_ReturnValue__pf = UKismetMathLibrary::FClamp(bpv__CallFunc_Add_FloatFloat_ReturnValue__pf, 0.000000, 1.000000);
				bpv__CallFunc_LinearColorLerp_ReturnValue__pf = UKismetMathLibrary::LinearColorLerp(FLinearColor(1.000000,0.221000,0.040000,1.000000), FLinearColor(0.954000,0.901000,0.744120,1.000000), bpv__CallFunc_FClamp_ReturnValue__pf);
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Sun color")), bpv__CallFunc_LinearColorLerp_ReturnValue__pf);
				}
				CurrentState = 9;
				break;
			}
		case 21:
			{
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Horizon color")), bpv__Horizonxcolor__pfT);
				}
			}
		case 22:
			{
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Zenith color")), bpv__ZenithxColor__pfT);
				}
			}
		case 23:
			{
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Overall color")), bpv__OverallxColor__pfT);
				}
			}
		case 24:
			{
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Cloud color")), bpv__Cloudxcolor__pfT);
				}
			}
		case 25:
			{
				if(IsValid(bpv__Skyxmaterial__pfT))
				{
					bpv__Skyxmaterial__pfT->SetScalarParameterValue(FName(TEXT("Horizon falloff")), bpv__HorizonxFalloff__pfT);
				}
				CurrentState = 14;
				break;
			}
		default:
			break;
		}
	} while( CurrentState != -1 );
}
void ABP_Sky_Sphere_C__pf2298762097::bpf__UpdateSunDirection__pf()
{
	bool bpv__CallFunc_Less_FloatFloat_ReturnValue__pf{};
	FRotator bpv__CallFunc_K2_GetActorRotation_ReturnValue__pf(EForceInit::ForceInit);
	float bpv__CallFunc_Abs_ReturnValue__pf{};
	float bpv__CallFunc_BreakRotator_Roll__pf{};
	float bpv__CallFunc_BreakRotator_Pitch__pf{};
	float bpv__CallFunc_BreakRotator_Yaw__pf{};
	float bpv__CallFunc_SelectFloat_ReturnValue__pf{};
	float bpv__CallFunc_MapRangeUnclamped_ReturnValue__pf{};
	FRotator bpv__CallFunc_K2_GetActorRotation_ReturnValue2__pf(EForceInit::ForceInit);
	FLinearColor bpv__CallFunc_Conv_ColorToLinearColor_ReturnValue__pf(EForceInit::ForceInit);
	FVector bpv__CallFunc_Conv_RotatorToVector_ReturnValue__pf(EForceInit::ForceInit);
	FLinearColor bpv__CallFunc_Conv_VectorToLinearColor_ReturnValue__pf(EForceInit::ForceInit);
	float bpv__CallFunc_Abs_ReturnValue2__pf{};
	FLinearColor bpv__CallFunc_GetLinearColorValue_ReturnValue__pf(EForceInit::ForceInit);
	float bpv__CallFunc_Lerp_ReturnValue__pf{};
	FLinearColor bpv__CallFunc_GetLinearColorValue_ReturnValue2__pf(EForceInit::ForceInit);
	FLinearColor bpv__CallFunc_GetLinearColorValue_ReturnValue3__pf(EForceInit::ForceInit);
	if(IsValid(bpv__Directionalxlightxactor__pfTT))
	{
		bpv__CallFunc_K2_GetActorRotation_ReturnValue2__pf = bpv__Directionalxlightxactor__pfTT->K2_GetActorRotation();
	}
	bpv__CallFunc_Conv_RotatorToVector_ReturnValue__pf = UKismetMathLibrary::Conv_RotatorToVector(bpv__CallFunc_K2_GetActorRotation_ReturnValue2__pf);
	bpv__CallFunc_Conv_VectorToLinearColor_ReturnValue__pf = UKismetMathLibrary::Conv_VectorToLinearColor(bpv__CallFunc_Conv_RotatorToVector_ReturnValue__pf);
	if(IsValid(bpv__Skyxmaterial__pfT))
	{
		bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Light direction")), bpv__CallFunc_Conv_VectorToLinearColor_ReturnValue__pf);
	}
	FColor  __Local__6 = FColor(0,0,0,255);
	bpv__CallFunc_Conv_ColorToLinearColor_ReturnValue__pf = UKismetMathLibrary::Conv_ColorToLinearColor(((IsValid(bpv__Directionalxlightxactor__pfTT) && IsValid(bpv__Directionalxlightxactor__pfTT->LightComponent)) ? (bpv__Directionalxlightxactor__pfTT->LightComponent->LightColor) : (__Local__6)));
	if(IsValid(bpv__Skyxmaterial__pfT))
	{
		bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Sun color")), bpv__CallFunc_Conv_ColorToLinearColor_ReturnValue__pf);
	}
	if(IsValid(bpv__Directionalxlightxactor__pfTT))
	{
		bpv__CallFunc_K2_GetActorRotation_ReturnValue__pf = bpv__Directionalxlightxactor__pfTT->K2_GetActorRotation();
	}
	UKismetMathLibrary::BreakRotator(bpv__CallFunc_K2_GetActorRotation_ReturnValue__pf, /*out*/ bpv__CallFunc_BreakRotator_Roll__pf, /*out*/ bpv__CallFunc_BreakRotator_Pitch__pf, /*out*/ bpv__CallFunc_BreakRotator_Yaw__pf);
	bpv__CallFunc_MapRangeUnclamped_ReturnValue__pf = UKismetMathLibrary::MapRangeUnclamped(bpv__CallFunc_BreakRotator_Pitch__pf, 0.000000, -90.000000, 0.000000, 1.000000);
	bpv__Sunxheight__pfT = bpv__CallFunc_MapRangeUnclamped_ReturnValue__pf;
	if(IsValid(bpv__Horizonxcolorxcurve__pfTT))
	{
		bpv__CallFunc_GetLinearColorValue_ReturnValue3__pf = bpv__Horizonxcolorxcurve__pfTT->GetLinearColorValue(bpv__Sunxheight__pfT);
	}
	if(IsValid(bpv__Skyxmaterial__pfT))
	{
		bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Horizon color")), bpv__CallFunc_GetLinearColorValue_ReturnValue3__pf);
	}
	if(IsValid(bpv__Zenithxcolorxcurve__pfTT))
	{
		bpv__CallFunc_GetLinearColorValue_ReturnValue2__pf = bpv__Zenithxcolorxcurve__pfTT->GetLinearColorValue(bpv__Sunxheight__pfT);
	}
	if(IsValid(bpv__Skyxmaterial__pfT))
	{
		bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Zenith color")), bpv__CallFunc_GetLinearColorValue_ReturnValue2__pf);
	}
	if(IsValid(bpv__Cloudxcolorxcurve__pfTT))
	{
		bpv__CallFunc_GetLinearColorValue_ReturnValue__pf = bpv__Cloudxcolorxcurve__pfTT->GetLinearColorValue(bpv__Sunxheight__pfT);
	}
	if(IsValid(bpv__Skyxmaterial__pfT))
	{
		bpv__Skyxmaterial__pfT->SetVectorParameterValue(FName(TEXT("Cloud color")), bpv__CallFunc_GetLinearColorValue_ReturnValue__pf);
	}
	bpv__CallFunc_Abs_ReturnValue2__pf = UKismetMathLibrary::Abs(bpv__Sunxheight__pfT);
	bpv__CallFunc_Lerp_ReturnValue__pf = UKismetMathLibrary::Lerp(3.000000, 8.000000, bpv__CallFunc_Abs_ReturnValue2__pf);
	if(IsValid(bpv__Skyxmaterial__pfT))
	{
		bpv__Skyxmaterial__pfT->SetScalarParameterValue(FName(TEXT("Horizon falloff")), bpv__CallFunc_Lerp_ReturnValue__pf);
	}
	bpv__CallFunc_Less_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Less_FloatFloat(bpv__Sunxheight__pfT, 0.000000);
	bpv__CallFunc_Abs_ReturnValue__pf = UKismetMathLibrary::Abs(bpv__Sunxheight__pfT);
	bpv__CallFunc_SelectFloat_ReturnValue__pf = UKismetMathLibrary::SelectFloat(bpv__CallFunc_Abs_ReturnValue__pf, 0.000000, bpv__CallFunc_Less_FloatFloat_ReturnValue__pf);
	if(IsValid(bpv__Skyxmaterial__pfT))
	{
		bpv__Skyxmaterial__pfT->SetScalarParameterValue(FName(TEXT("Sun height")), bpv__CallFunc_SelectFloat_ReturnValue__pf);
	}
}
void ABP_Sky_Sphere_C__pf2298762097::__StaticDependencies_CommonAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	FBlueprintDependencyData LocAssets[] =
	{
		FBlueprintDependencyData(TEXT("/Engine/EngineSky/SM_SkySphere"), TEXT("SM_SkySphere"), TEXT("/Script/Engine"), TEXT("StaticMesh")),
		FBlueprintDependencyData(TEXT("/Engine/EngineSky/M_Sky_Panning_Clouds2"), TEXT("M_Sky_Panning_Clouds2"), TEXT("/Script/Engine"), TEXT("Material")),
		FBlueprintDependencyData(TEXT("/Engine/EngineSky/C_Sky_Horizon_Color"), TEXT("C_Sky_Horizon_Color"), TEXT("/Script/Engine"), TEXT("CurveLinearColor")),
		FBlueprintDependencyData(TEXT("/Engine/EngineSky/C_Sky_Zenith_Color"), TEXT("C_Sky_Zenith_Color"), TEXT("/Script/Engine"), TEXT("CurveLinearColor")),
		FBlueprintDependencyData(TEXT("/Engine/EngineSky/C_Sky_Cloud_Color"), TEXT("C_Sky_Cloud_Color"), TEXT("/Script/Engine"), TEXT("CurveLinearColor")),
	};
	for(auto& LocAsset : LocAssets) { AssetsToLoad.Add(LocAsset); } 
}
void ABP_Sky_Sphere_C__pf2298762097::__StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_CommonAssets(AssetsToLoad);
}
void ABP_Sky_Sphere_C__pf2298762097::__StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_CommonAssets(AssetsToLoad);
}
struct FRegisterHelper__ABP_Sky_Sphere_C__pf2298762097
{
	FRegisterHelper__ABP_Sky_Sphere_C__pf2298762097()
	{
		FConvertedBlueprintsDependencies::Get().RegisterClass(TEXT("/Engine/EngineSky/BP_Sky_Sphere"), &ABP_Sky_Sphere_C__pf2298762097::__StaticDependenciesAssets);
	}
	static FRegisterHelper__ABP_Sky_Sphere_C__pf2298762097 Instance;
};
FRegisterHelper__ABP_Sky_Sphere_C__pf2298762097 FRegisterHelper__ABP_Sky_Sphere_C__pf2298762097::Instance;
#ifdef _MSC_VER
#pragma warning (pop)
#endif
