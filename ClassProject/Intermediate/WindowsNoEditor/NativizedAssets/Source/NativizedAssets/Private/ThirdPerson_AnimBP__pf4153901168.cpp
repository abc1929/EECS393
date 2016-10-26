#include "NativizedAssets.h"
#include "ThirdPerson_AnimBP__pf4153901168.h"
#include "GeneratedCodeHelpers.h"
#include "Animation/BlendProfile.h"
#include "Runtime/Engine/Classes/Animation/Skeleton.h"
#include "ThirdPerson_AnimBP__pf4153901168.h"
#include "Runtime/Engine/Classes/Animation/AnimNodeBase.h"
#include "Runtime/Engine/Classes/Animation/AnimNode_AssetPlayerBase.h"
#include "Runtime/Engine/Classes/Animation/AnimationAsset.h"
#include "Runtime/Engine/Classes/Animation/BlendSpaceBase.h"
#include "Runtime/Engine/Classes/Engine/AssetUserData.h"
#include "Runtime/Engine/Classes/Animation/AnimMetaData.h"
#include "Runtime/Engine/Classes/Animation/BlendProfile.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMesh.h"
#include "Runtime/Engine/Classes/Animation/SmartName.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshSocket.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SkinnedMeshComponent.h"
#include "Runtime/Engine/Classes/Components/MeshComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/TouchInterface.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Engine/Classes/Engine/Texture.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_AssetUserData.h"
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
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterialPropertyBase.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsSettingsEnums.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/Materials/MaterialInterface.h"
#include "Runtime/Engine/Classes/Engine/SubsurfaceProfile.h"
#include "Runtime/Engine/Classes/Materials/Material.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpression.h"
#include "Runtime/Engine/Classes/Engine/BlendableInterface.h"
#include "Runtime/Engine/Public/ParticleHelper.h"
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
#include "Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "Runtime/Engine/Classes/Curves/CurveBase.h"
#include "Runtime/Engine/Classes/Curves/RichCurve.h"
#include "Runtime/Engine/Classes/Curves/IndexedCurve.h"
#include "Runtime/Engine/Classes/Curves/KeyHandle.h"
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
#include "Runtime/Engine/Classes/Engine/EngineBaseTypes.h"
#include "Runtime/Engine/Classes/Engine/NetSerialization.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawn.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPawn.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_CollisionDataProvider.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Components/ShapeComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAreas/NavArea.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationTypes.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetup.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodyInstance.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetupEnums.h"
#include "Runtime/Engine/Classes/PhysicsEngine/AggregateGeom.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConvexElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ShapeElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphylElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BoxElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphereElem.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAreas/NavArea_Obstacle.h"
#include "Runtime/Engine/Classes/GameFramework/PawnMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/NavMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/MovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PhysicsVolume.h"
#include "Runtime/Engine/Classes/GameFramework/Volume.h"
#include "Runtime/Engine/Classes/Engine/Brush.h"
#include "Runtime/Engine/Classes/Components/BrushComponent.h"
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
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "Runtime/Engine/Classes/Animation/AnimCompositeBase.h"
#include "Runtime/Engine/Classes/Animation/AnimSequenceBase.h"
#include "Runtime/Engine/Public/Animation/AnimCurveTypes.h"
#include "Runtime/Engine/Public/Animation/AnimTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimLinkableElement.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "Runtime/Engine/Public/AlphaBlend.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/RootMotionSource.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationAvoidanceTypes.h"
#include "Runtime/Engine/Public/AI/RVOAvoidanceInterface.h"
#include "Runtime/Engine/Classes/Interfaces/NetworkPredictionInterface.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAgentInterface.h"
#include "Runtime/Engine/Classes/Components/ChildActorComponent.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphPin.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavRelevantInterface.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsAsset.h"
#include "Runtime/Engine/Classes/Animation/AnimSequence.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Engine/BlueprintGeneratedClass.h"
#include "Runtime/Engine/Classes/Animation/BlendSpace1D.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
UThirdPerson_AnimBP_C__pf4153901168::UThirdPerson_AnimBP_C__pf4153901168(const FObjectInitializer& ObjectInitializer) : Super()
{
	if(HasAnyFlags(RF_ClassDefaultObject) && (UThirdPerson_AnimBP_C__pf4153901168::StaticClass() == GetClass()))
	{
		UThirdPerson_AnimBP_C__pf4153901168::__CustomDynamicClassInitialization(CastChecked<UDynamicClass>(GetClass()));
	}
	
	bpv__AnimGraphNode_Root_6245415D43FCCBD818C7DD8DCFD4FBC8__pf.Result.LinkID = 13;
	bpv__AnimGraphNode_TransitionResult_175FFF54400CA0EC412B7083B0989D7E__pf.EvaluateGraphExposedInputs.BoundFunction = FName(TEXT("EvaluateGraphExposedInputs_ExecuteUbergraph_ThirdPerson_AnimBP_AnimGraphNode_TransitionResult_175FFF54400CA0EC412B7083B0989D7E"));
	bpv__AnimGraphNode_TransitionResult_EB26C4B44509776D1C9FA6991E047C32__pf.EvaluateGraphExposedInputs.CopyRecords = TArray<FExposedValueCopyRecord> ();
	bpv__AnimGraphNode_TransitionResult_EB26C4B44509776D1C9FA6991E047C32__pf.EvaluateGraphExposedInputs.CopyRecords.AddUninitialized(1);
	FExposedValueCopyRecord::StaticStruct()->InitializeStruct(bpv__AnimGraphNode_TransitionResult_EB26C4B44509776D1C9FA6991E047C32__pf.EvaluateGraphExposedInputs.CopyRecords.GetData(), 1);
	auto& __Local__0 = bpv__AnimGraphNode_TransitionResult_EB26C4B44509776D1C9FA6991E047C32__pf.EvaluateGraphExposedInputs.CopyRecords[0];
	__Local__0.SourcePropertyName = FName(TEXT("IsInAir?"));
	__Local__0.DestProperty = FindFieldChecked<UBoolProperty>(FAnimNode_TransitionResult::StaticStruct(), TEXT("bCanEnterTransition"));
	__Local__0.Size = 1;
	__Local__0.PostCopyOperation = EPostCopyOperation::LogicalNegateBool;
	bpv__AnimGraphNode_TransitionResult_F867B5374C7EFB9ED9010FA7431019DF__pf.EvaluateGraphExposedInputs.BoundFunction = FName(TEXT("EvaluateGraphExposedInputs_ExecuteUbergraph_ThirdPerson_AnimBP_AnimGraphNode_TransitionResult_F867B5374C7EFB9ED9010FA7431019DF"));
	bpv__AnimGraphNode_TransitionResult_EA982A1F4C5300ED41A13CAD26E05A19__pf.EvaluateGraphExposedInputs.CopyRecords = TArray<FExposedValueCopyRecord> ();
	bpv__AnimGraphNode_TransitionResult_EA982A1F4C5300ED41A13CAD26E05A19__pf.EvaluateGraphExposedInputs.CopyRecords.AddUninitialized(1);
	FExposedValueCopyRecord::StaticStruct()->InitializeStruct(bpv__AnimGraphNode_TransitionResult_EA982A1F4C5300ED41A13CAD26E05A19__pf.EvaluateGraphExposedInputs.CopyRecords.GetData(), 1);
	auto& __Local__1 = bpv__AnimGraphNode_TransitionResult_EA982A1F4C5300ED41A13CAD26E05A19__pf.EvaluateGraphExposedInputs.CopyRecords[0];
	__Local__1.SourcePropertyName = FName(TEXT("IsInAir?"));
	__Local__1.DestProperty = FindFieldChecked<UBoolProperty>(FAnimNode_TransitionResult::StaticStruct(), TEXT("bCanEnterTransition"));
	__Local__1.Size = 1;
	bpv__AnimGraphNode_SequencePlayer_A0CF690444C363144EC28B95406387AA__pf.Sequence = CastChecked<UAnimSequenceBase>(CastChecked<UDynamicClass>(UThirdPerson_AnimBP_C__pf4153901168::StaticClass())->UsedAssets[2], ECastCheckedType::NullAllowed);
	bpv__AnimGraphNode_SequencePlayer_A0CF690444C363144EC28B95406387AA__pf.bLoopAnimation = false;
	bpv__AnimGraphNode_StateResult_297D99FF44D47FD485B4F89D8011EE52__pf.Result.LinkID = 5;
	bpv__AnimGraphNode_SequencePlayer_7F3D9C864B693C7A42B6BE9C6E030836__pf.Sequence = CastChecked<UAnimSequenceBase>(CastChecked<UDynamicClass>(UThirdPerson_AnimBP_C__pf4153901168::StaticClass())->UsedAssets[3], ECastCheckedType::NullAllowed);
	bpv__AnimGraphNode_SequencePlayer_7F3D9C864B693C7A42B6BE9C6E030836__pf.PlayRate = 0.750000f;
	bpv__AnimGraphNode_StateResult_1EBEFD1E44C9887ACE06AC8147E389E1__pf.Result.LinkID = 7;
	bpv__AnimGraphNode_SequencePlayer_42CC18D944758414A1674994127217DE__pf.Sequence = CastChecked<UAnimSequenceBase>(CastChecked<UDynamicClass>(UThirdPerson_AnimBP_C__pf4153901168::StaticClass())->UsedAssets[1], ECastCheckedType::NullAllowed);
	bpv__AnimGraphNode_SequencePlayer_42CC18D944758414A1674994127217DE__pf.bLoopAnimation = false;
	bpv__AnimGraphNode_StateResult_046F1C2548286DB7421A07BCB8B9830E__pf.Result.LinkID = 9;
	bpv__AnimGraphNode_BlendSpacePlayer_02DCCD344B15638E3A268A84A40F216E__pf.BlendSpace = CastChecked<UBlendSpaceBase>(CastChecked<UDynamicClass>(UThirdPerson_AnimBP_C__pf4153901168::StaticClass())->UsedAssets[4], ECastCheckedType::NullAllowed);
	bpv__AnimGraphNode_BlendSpacePlayer_02DCCD344B15638E3A268A84A40F216E__pf.EvaluateGraphExposedInputs.CopyRecords = TArray<FExposedValueCopyRecord> ();
	bpv__AnimGraphNode_BlendSpacePlayer_02DCCD344B15638E3A268A84A40F216E__pf.EvaluateGraphExposedInputs.CopyRecords.AddUninitialized(1);
	FExposedValueCopyRecord::StaticStruct()->InitializeStruct(bpv__AnimGraphNode_BlendSpacePlayer_02DCCD344B15638E3A268A84A40F216E__pf.EvaluateGraphExposedInputs.CopyRecords.GetData(), 1);
	auto& __Local__2 = bpv__AnimGraphNode_BlendSpacePlayer_02DCCD344B15638E3A268A84A40F216E__pf.EvaluateGraphExposedInputs.CopyRecords[0];
	__Local__2.SourcePropertyName = FName(TEXT("Speed"));
	__Local__2.DestProperty = FindFieldChecked<UFloatProperty>(FAnimNode_BlendSpacePlayer::StaticStruct(), TEXT("X"));
	__Local__2.Size = 4;
	bpv__AnimGraphNode_StateResult_7618737141064086BB77CBB9D5CD2D59__pf.Result.LinkID = 11;
	bpv__IsInAirx__pfzy = false;
	bpv__Speed__pf = 0.000000f;
}
void UThirdPerson_AnimBP_C__pf4153901168::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
}
void UThirdPerson_AnimBP_C__pf4153901168::__CustomDynamicClassInitialization(UDynamicClass* InDynamicClass)
{
	ensure(0 == InDynamicClass->ReferencedConvertedFields.Num());
	ensure(0 == InDynamicClass->MiscConvertedSubobjects.Num());
	ensure(0 == InDynamicClass->DynamicBindingObjects.Num());
	ensure(0 == InDynamicClass->ComponentTemplates.Num());
	ensure(0 == InDynamicClass->Timelines.Num());
	ensure(nullptr == InDynamicClass->AnimClassImplementation);
	InDynamicClass->AssembleReferenceTokenStream();
	FConvertedBlueprintsDependencies::FillUsedAssetsInDynamicClass(InDynamicClass, &__StaticDependencies_DirectlyUsedAssets);
	auto __Local__3 = NewObject<UAnimClassData>(InDynamicClass, TEXT("AnimClassData"));
	__Local__3->BakedStateMachines = TArray<FBakedAnimationStateMachine> ();
	__Local__3->BakedStateMachines.AddUninitialized(1);
	FBakedAnimationStateMachine::StaticStruct()->InitializeStruct(__Local__3->BakedStateMachines.GetData(), 1);
	auto& __Local__4 = __Local__3->BakedStateMachines[0];
	__Local__4.MachineName = FName(TEXT("Default"));
	__Local__4.InitialState = 0;
	__Local__4.States = TArray<FBakedAnimationState> ();
	__Local__4.States.AddUninitialized(4);
	FBakedAnimationState::StaticStruct()->InitializeStruct(__Local__4.States.GetData(), 4);
	auto& __Local__5 = __Local__4.States[0];
	__Local__5.StateName = FName(TEXT("Idle/Run"));
	__Local__5.Transitions = TArray<FBakedStateExitTransition> ();
	__Local__5.Transitions.AddUninitialized(1);
	FBakedStateExitTransition::StaticStruct()->InitializeStruct(__Local__5.Transitions.GetData(), 1);
	auto& __Local__6 = __Local__5.Transitions[0];
	__Local__6.CanTakeDelegateIndex = 9;
	__Local__6.TransitionIndex = 0;
	__Local__5.StateRootNodeIndex = 1;
	__Local__5.PlayerNodeIndices = TArray<int32> ();
	__Local__5.PlayerNodeIndices.Reserve(1);
	__Local__5.PlayerNodeIndices.Add(2);
	auto& __Local__7 = __Local__4.States[1];
	__Local__7.StateName = FName(TEXT("JumpStart"));
	__Local__7.Transitions = TArray<FBakedStateExitTransition> ();
	__Local__7.Transitions.AddUninitialized(1);
	FBakedStateExitTransition::StaticStruct()->InitializeStruct(__Local__7.Transitions.GetData(), 1);
	auto& __Local__8 = __Local__7.Transitions[0];
	__Local__8.CanTakeDelegateIndex = 10;
	__Local__8.TransitionIndex = 1;
	__Local__7.StateRootNodeIndex = 3;
	__Local__7.PlayerNodeIndices = TArray<int32> ();
	__Local__7.PlayerNodeIndices.Reserve(1);
	__Local__7.PlayerNodeIndices.Add(4);
	auto& __Local__9 = __Local__4.States[2];
	__Local__9.StateName = FName(TEXT("JumpLoop"));
	__Local__9.Transitions = TArray<FBakedStateExitTransition> ();
	__Local__9.Transitions.AddUninitialized(1);
	FBakedStateExitTransition::StaticStruct()->InitializeStruct(__Local__9.Transitions.GetData(), 1);
	auto& __Local__10 = __Local__9.Transitions[0];
	__Local__10.CanTakeDelegateIndex = 11;
	__Local__10.TransitionIndex = 3;
	__Local__9.StateRootNodeIndex = 5;
	__Local__9.PlayerNodeIndices = TArray<int32> ();
	__Local__9.PlayerNodeIndices.Reserve(1);
	__Local__9.PlayerNodeIndices.Add(6);
	auto& __Local__11 = __Local__4.States[3];
	__Local__11.StateName = FName(TEXT("JumpEnd"));
	__Local__11.Transitions = TArray<FBakedStateExitTransition> ();
	__Local__11.Transitions.AddUninitialized(1);
	FBakedStateExitTransition::StaticStruct()->InitializeStruct(__Local__11.Transitions.GetData(), 1);
	auto& __Local__12 = __Local__11.Transitions[0];
	__Local__12.CanTakeDelegateIndex = 12;
	__Local__12.TransitionIndex = 2;
	__Local__11.StateRootNodeIndex = 7;
	__Local__11.PlayerNodeIndices = TArray<int32> ();
	__Local__11.PlayerNodeIndices.Reserve(1);
	__Local__11.PlayerNodeIndices.Add(8);
	__Local__4.Transitions = TArray<FAnimationTransitionBetweenStates> ();
	__Local__4.Transitions.AddUninitialized(4);
	FAnimationTransitionBetweenStates::StaticStruct()->InitializeStruct(__Local__4.Transitions.GetData(), 4);
	auto& __Local__13 = __Local__4.Transitions[0];
	__Local__13.PreviousState = 0;
	__Local__13.NextState = 1;
	__Local__13.CrossfadeDuration = 0.200000f;
	__Local__13.BlendMode = EAlphaBlendOption::HermiteCubic;
	auto& __Local__14 = __Local__4.Transitions[1];
	__Local__14.PreviousState = 1;
	__Local__14.NextState = 2;
	__Local__14.CrossfadeDuration = 0.200000f;
	__Local__14.BlendMode = EAlphaBlendOption::HermiteCubic;
	auto& __Local__15 = __Local__4.Transitions[2];
	__Local__15.PreviousState = 3;
	__Local__15.NextState = 0;
	__Local__15.CrossfadeDuration = 0.200000f;
	__Local__15.BlendMode = EAlphaBlendOption::HermiteCubic;
	auto& __Local__16 = __Local__4.Transitions[3];
	__Local__16.PreviousState = 2;
	__Local__16.NextState = 3;
	__Local__16.CrossfadeDuration = 0.200000f;
	__Local__16.BlendMode = EAlphaBlendOption::HermiteCubic;
	__Local__3->TargetSkeleton = CastChecked<USkeleton>(CastChecked<UDynamicClass>(UThirdPerson_AnimBP_C__pf4153901168::StaticClass())->UsedAssets[0], ECastCheckedType::NullAllowed);
	__Local__3->RootAnimNodeIndex = 13;
	__Local__3->RootAnimNodeProperty = FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_Root_6245415D43FCCBD818C7DD8DCFD4FBC8"));
	__Local__3->AnimNodeProperties = TArray<UStructProperty*> ();
	__Local__3->AnimNodeProperties.Reserve(14);
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_Root_6245415D43FCCBD818C7DD8DCFD4FBC8")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_TransitionResult_175FFF54400CA0EC412B7083B0989D7E")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_TransitionResult_EB26C4B44509776D1C9FA6991E047C32")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_TransitionResult_F867B5374C7EFB9ED9010FA7431019DF")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_TransitionResult_EA982A1F4C5300ED41A13CAD26E05A19")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_SequencePlayer_A0CF690444C363144EC28B95406387AA")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_StateResult_297D99FF44D47FD485B4F89D8011EE52")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_SequencePlayer_7F3D9C864B693C7A42B6BE9C6E030836")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_StateResult_1EBEFD1E44C9887ACE06AC8147E389E1")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_SequencePlayer_42CC18D944758414A1674994127217DE")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_StateResult_046F1C2548286DB7421A07BCB8B9830E")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_BlendSpacePlayer_02DCCD344B15638E3A268A84A40F216E")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_StateResult_7618737141064086BB77CBB9D5CD2D59")));
	__Local__3->AnimNodeProperties.Add(FindFieldChecked<UStructProperty>(InDynamicClass, TEXT("AnimGraphNode_StateMachine_4DC365404548467BD671AEB325E4717D")));
	InDynamicClass->AnimClassImplementation = __Local__3;
}
void UThirdPerson_AnimBP_C__pf4153901168::bpf__ExecuteUbergraph_ThirdPerson_AnimBP__pf_0(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 1);
	// optimized KCST_UnconditionalGoto
	b0l__CallFunc_TryGetPawnOwner_ReturnValue__pf = TryGetPawnOwner();
	b0l__CallFunc_IsValid_ReturnValue__pf = UKismetSystemLibrary::IsValid(b0l__CallFunc_TryGetPawnOwner_ReturnValue__pf);
	if (!b0l__CallFunc_IsValid_ReturnValue__pf)
	{
		return; //KCST_GotoReturnIfNot
	}
	b0l__CallFunc_TryGetPawnOwner_ReturnValue__pf = TryGetPawnOwner();
	if(IsValid(b0l__CallFunc_TryGetPawnOwner_ReturnValue__pf))
	{
		b0l__CallFunc_GetMovementComponent_ReturnValue__pf = b0l__CallFunc_TryGetPawnOwner_ReturnValue__pf->GetMovementComponent();
	}
	if(IsValid(b0l__CallFunc_GetMovementComponent_ReturnValue__pf))
	{
		b0l__CallFunc_IsFalling_ReturnValue__pf = b0l__CallFunc_GetMovementComponent_ReturnValue__pf->IsFalling();
	}
	bpv__IsInAirx__pfzy = b0l__CallFunc_IsFalling_ReturnValue__pf;
	b0l__CallFunc_TryGetPawnOwner_ReturnValue__pf = TryGetPawnOwner();
	if(IsValid(b0l__CallFunc_TryGetPawnOwner_ReturnValue__pf))
	{
		b0l__CallFunc_GetVelocity_ReturnValue__pf = b0l__CallFunc_TryGetPawnOwner_ReturnValue__pf->GetVelocity();
	}
	b0l__CallFunc_VSize_ReturnValue__pf = UKismetMathLibrary::VSize(b0l__CallFunc_GetVelocity_ReturnValue__pf);
	bpv__Speed__pf = b0l__CallFunc_VSize_ReturnValue__pf;
	return; // KCST_GotoReturn
}
void UThirdPerson_AnimBP_C__pf4153901168::bpf__ExecuteUbergraph_ThirdPerson_AnimBP__pf_1(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 6);
	// optimized KCST_UnconditionalGoto
	static TWeakObjectPtr<UProperty> __Local__18{};
	const UProperty* __Local__17 = __Local__18.Get();
	if (nullptr == __Local__17)
	{
		__Local__17 = (FAnimNode_AssetPlayerBase::StaticStruct())->FindPropertyByName(FName(TEXT("InternalTimeAccumulator")));
		check(__Local__17);
		__Local__18 = __Local__17;
	}
	b0l__CallFunc_GetAnimAssetPlayerTimeFromEndFraction_ReturnValue2__pf = UAnimInstance::GetAnimAssetPlayerTimeFromEndFraction(CastChecked<UAnimationAsset>(CastChecked<UDynamicClass>(UThirdPerson_AnimBP_C__pf4153901168::StaticClass())->UsedAssets[1], ECastCheckedType::NullAllowed), (*(__Local__17->ContainerPtrToValuePtr<float >(&(bpv__AnimGraphNode_SequencePlayer_42CC18D944758414A1674994127217DE__pf), 0))));
	b0l__CallFunc_Less_FloatFloat_ReturnValue2__pf = UKismetMathLibrary::Less_FloatFloat(b0l__CallFunc_GetAnimAssetPlayerTimeFromEndFraction_ReturnValue2__pf, 0.100000);
	bpv__AnimGraphNode_TransitionResult_F867B5374C7EFB9ED9010FA7431019DF__pf.bCanEnterTransition = b0l__CallFunc_Less_FloatFloat_ReturnValue2__pf;
	return; // KCST_GotoReturn
}
void UThirdPerson_AnimBP_C__pf4153901168::bpf__ExecuteUbergraph_ThirdPerson_AnimBP__pf_2(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 10);
	// optimized KCST_UnconditionalGoto
	static TWeakObjectPtr<UProperty> __Local__20{};
	const UProperty* __Local__19 = __Local__20.Get();
	if (nullptr == __Local__19)
	{
		__Local__19 = (FAnimNode_AssetPlayerBase::StaticStruct())->FindPropertyByName(FName(TEXT("InternalTimeAccumulator")));
		check(__Local__19);
		__Local__20 = __Local__19;
	}
	b0l__CallFunc_GetAnimAssetPlayerTimeFromEndFraction_ReturnValue__pf = UAnimInstance::GetAnimAssetPlayerTimeFromEndFraction(CastChecked<UAnimationAsset>(CastChecked<UDynamicClass>(UThirdPerson_AnimBP_C__pf4153901168::StaticClass())->UsedAssets[2], ECastCheckedType::NullAllowed), (*(__Local__19->ContainerPtrToValuePtr<float >(&(bpv__AnimGraphNode_SequencePlayer_A0CF690444C363144EC28B95406387AA__pf), 0))));
	b0l__CallFunc_Less_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Less_FloatFloat(b0l__CallFunc_GetAnimAssetPlayerTimeFromEndFraction_ReturnValue__pf, 0.100000);
	bpv__AnimGraphNode_TransitionResult_175FFF54400CA0EC412B7083B0989D7E__pf.bCanEnterTransition = b0l__CallFunc_Less_FloatFloat_ReturnValue__pf;
	return; // KCST_GotoReturn
}
void UThirdPerson_AnimBP_C__pf4153901168::bpf__ExecuteUbergraph_ThirdPerson_AnimBP__pf_3(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 8);
	// optimized KCST_UnconditionalGoto
	return; // KCST_GotoReturn
}
void UThirdPerson_AnimBP_C__pf4153901168::bpf__ExecuteUbergraph_ThirdPerson_AnimBP__pf_4(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 12);
	// optimized KCST_UnconditionalGoto
	return; // KCST_GotoReturn
}
void UThirdPerson_AnimBP_C__pf4153901168::bpf__ExecuteUbergraph_ThirdPerson_AnimBP__pf_5(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 14);
	// optimized KCST_UnconditionalGoto
	return; // KCST_GotoReturn
}
void UThirdPerson_AnimBP_C__pf4153901168::bpf__BlueprintUpdateAnimation__pf(float bpp__DeltaTimeX__pf)
{
	b0l__K2Node_Event_DeltaTimeX__pf = bpp__DeltaTimeX__pf;
	bpf__ExecuteUbergraph_ThirdPerson_AnimBP__pf_0(1);
}
void UThirdPerson_AnimBP_C__pf4153901168::bpf__EvaluateGraphExposedInputs_ExecuteUbergraph_ThirdPerson_AnimBP_AnimGraphNode_BlendSpacePlayer_02DCCD344B15638E3A268A84A40F216E__pf()
{
	bpf__ExecuteUbergraph_ThirdPerson_AnimBP__pf_3(8);
}
void UThirdPerson_AnimBP_C__pf4153901168::bpf__EvaluateGraphExposedInputs_ExecuteUbergraph_ThirdPerson_AnimBP_AnimGraphNode_TransitionResult_EA982A1F4C5300ED41A13CAD26E05A19__pf()
{
	bpf__ExecuteUbergraph_ThirdPerson_AnimBP__pf_5(14);
}
void UThirdPerson_AnimBP_C__pf4153901168::bpf__EvaluateGraphExposedInputs_ExecuteUbergraph_ThirdPerson_AnimBP_AnimGraphNode_TransitionResult_F867B5374C7EFB9ED9010FA7431019DF__pf()
{
	bpf__ExecuteUbergraph_ThirdPerson_AnimBP__pf_1(6);
}
void UThirdPerson_AnimBP_C__pf4153901168::bpf__EvaluateGraphExposedInputs_ExecuteUbergraph_ThirdPerson_AnimBP_AnimGraphNode_TransitionResult_EB26C4B44509776D1C9FA6991E047C32__pf()
{
	bpf__ExecuteUbergraph_ThirdPerson_AnimBP__pf_4(12);
}
void UThirdPerson_AnimBP_C__pf4153901168::bpf__EvaluateGraphExposedInputs_ExecuteUbergraph_ThirdPerson_AnimBP_AnimGraphNode_TransitionResult_175FFF54400CA0EC412B7083B0989D7E__pf()
{
	bpf__ExecuteUbergraph_ThirdPerson_AnimBP__pf_2(10);
}
void UThirdPerson_AnimBP_C__pf4153901168::__StaticDependencies_CommonAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	FBlueprintDependencyData LocAssets[] =
	{
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Character/Mesh/UE4_Mannequin_Skeleton"), TEXT("UE4_Mannequin_Skeleton"), TEXT("/Script/Engine"), TEXT("Skeleton")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPersonJump_Start"), TEXT("ThirdPersonJump_Start"), TEXT("/Script/Engine"), TEXT("AnimSequence")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPerson_Jump"), TEXT("ThirdPerson_Jump"), TEXT("/Script/Engine"), TEXT("AnimSequence")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPersonJump_Loop"), TEXT("ThirdPersonJump_Loop"), TEXT("/Script/Engine"), TEXT("AnimSequence")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPerson_IdleRun_2D"), TEXT("ThirdPerson_IdleRun_2D"), TEXT("/Script/Engine"), TEXT("BlendSpace1D")),
	};
	for(auto& LocAsset : LocAssets) { AssetsToLoad.Add(LocAsset); } 
}
void UThirdPerson_AnimBP_C__pf4153901168::__StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_CommonAssets(AssetsToLoad);
}
void UThirdPerson_AnimBP_C__pf4153901168::__StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_CommonAssets(AssetsToLoad);
}
struct FRegisterHelper__UThirdPerson_AnimBP_C__pf4153901168
{
	FRegisterHelper__UThirdPerson_AnimBP_C__pf4153901168()
	{
		FConvertedBlueprintsDependencies::Get().RegisterClass(TEXT("/Game/Mannequin/Animations/ThirdPerson_AnimBP"), &UThirdPerson_AnimBP_C__pf4153901168::__StaticDependenciesAssets);
	}
	static FRegisterHelper__UThirdPerson_AnimBP_C__pf4153901168 Instance;
};
FRegisterHelper__UThirdPerson_AnimBP_C__pf4153901168 FRegisterHelper__UThirdPerson_AnimBP_C__pf4153901168::Instance;
#ifdef _MSC_VER
#pragma warning (pop)
#endif
