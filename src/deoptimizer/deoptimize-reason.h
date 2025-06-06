// Copyright 2016 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_DEOPTIMIZER_DEOPTIMIZE_REASON_H_
#define V8_DEOPTIMIZER_DEOPTIMIZE_REASON_H_

#include "src/common/globals.h"

namespace v8 {
namespace internal {

// TODO(olivf, 420433007): We should have a custom BuiltinOutOfBounds reason
// which is only used when needed for builtin speculation. Currently this is
// not done since it would mean quite a major refactoring in Turbofan.
#define DEOPTIMIZE_IN_BUILTIN_REASON_LIST(V) \
  V(OutOfBounds, "out of bounds",            \
    SpeculationMode::kDisallowBoundsCheckSpeculation)

#define DEOPTIMIZE_REASON_LIST(V)                                              \
  DEOPTIMIZE_IN_BUILTIN_REASON_LIST(V)                                         \
  V(ArrayBufferWasDetached, "array buffer was detached")                       \
  V(ArrayLengthChanged, "the array length changed")                            \
  V(BigIntTooBig, "BigInt too big")                                            \
  V(ConstTrackingLet, "const tracking let constness invalidated")              \
  V(CouldNotGrowElements, "failed to grow elements store")                     \
  V(CowArrayElementsChanged, "copy-on-write array's elements changed")         \
  V(DeoptimizeNow, "%_DeoptimizeNow")                                          \
  V(DeprecatedMap, "deprecated map")                                           \
  V(DivisionByZero, "division by zero")                                        \
  V(Float16NotYetSupported, "float16 is not supported as machine operation")   \
  V(GreaterThanMaxFastElementArray,                                            \
    "length is greater than the maximum for fast elements array")              \
  V(Hole, "hole")                                                              \
  V(InstanceMigrationFailed, "instance migration failed")                      \
  V(InsufficientTypeFeedbackForArrayLiteral,                                   \
    "Insufficient type feedback for array literal")                            \
  V(InsufficientTypeFeedbackForBinaryOperation,                                \
    "Insufficient type feedback for binary operation")                         \
  V(InsufficientTypeFeedbackForCall, "Insufficient type feedback for call")    \
  V(InsufficientTypeFeedbackForCompareOperation,                               \
    "Insufficient type feedback for compare operation")                        \
  V(InsufficientTypeFeedbackForConstruct,                                      \
    "Insufficient type feedback for construct")                                \
  V(InsufficientTypeFeedbackForForIn, "Insufficient type feedback for for-in") \
  V(InsufficientTypeFeedbackForGenericGlobalAccess,                            \
    "Insufficient type feedback for generic global access")                    \
  V(InsufficientTypeFeedbackForGenericKeyedAccess,                             \
    "Insufficient type feedback for generic keyed access")                     \
  V(InsufficientTypeFeedbackForGenericNamedAccess,                             \
    "Insufficient type feedback for generic named access")                     \
  V(InsufficientTypeFeedbackForInstanceOf,                                     \
    "Insufficient type feedback for instanceof")                               \
  V(InsufficientTypeFeedbackForObjectLiteral,                                  \
    "Insufficient type feedback for object literal")                           \
  V(InsufficientTypeFeedbackForTypeOf,                                         \
    "Insufficient type feedback for typeof")                                   \
  V(InsufficientTypeFeedbackForUnaryOperation,                                 \
    "Insufficient type feedback for unary operation")                          \
  V(KeyedAccessChanged, "unexpected name in keyed access")                     \
  V(LostPrecision, "lost precision")                                           \
  V(LostPrecisionOrNaN, "lost precision or NaN")                               \
  V(MinusZero, "minus zero")                                                   \
  V(NaN, "NaN")                                                                \
  V(NoCache, "no cache")                                                       \
  V(NoInitialElement, "no initial element")                                    \
  V(NotABigInt, "not a BigInt")                                                \
  V(NotABigInt64, "not a BigInt64")                                            \
  V(NotAHeapNumber, "not a heap number")                                       \
  V(NotAJavaScriptObject, "not a JavaScript object")                           \
  V(NotAJavaScriptObjectOrNullOrUndefined,                                     \
    "not a JavaScript object, Null or Undefined")                              \
  V(NotANumber, "not a Number")                                                \
  V(NotANumberOrBoolean, "not a Number or Boolean")                            \
  V(NotANumberOrOddball, "not a Number or Oddball")                            \
  V(NotASmi, "not a Smi")                                                      \
  V(NotAString, "not a String")                                                \
  V(NotASeqOneByteString, "not a sequential one-byte String")                  \
  V(NotAStringOrStringWrapper, "not a String or a string wrapper")             \
  V(NotAStringWrapper, "not a string wrapper")                                 \
  V(NotAStringOrOddball, "not a String or oddball")                            \
  V(NotASymbol, "not a Symbol")                                                \
  V(NotAdditiveSafeInteger, "not AdditiveSafeInteger")                         \
  V(NotAnArrayIndex, "not an array index")                                     \
  V(NotDetectableReceiver, "not a detectable receiver")                        \
  V(NotInt32, "not int32")                                                     \
  V(NotUint32, "not unsigned int32")                                           \
  V(OSREarlyExit, "exit from OSR'd inner loop")                                \
  V(Overflow, "overflow")                                                      \
  V(PrepareForOnStackReplacement, "prepare for on stack replacement (OSR)")    \
  V(Smi, "Smi")                                                                \
  V(StoreToConstant, "Storing to a constant field")                            \
  V(StringTooLarge, "Result string larger than String::kMaxLength")            \
  V(SuspendGeneratorIsDead, "SuspendGenerator is in a dead branch")            \
  V(UnexpectedContextExtension, "unexpected context extension")                \
  V(Unknown, "(unknown)")                                                      \
  V(UnoptimizedCatch, "First use of catch block")                              \
  V(ValueMismatch, "value mismatch")                                           \
  V(WrongCallTarget, "wrong call target")                                      \
  V(WrongConstructor, "wrong call target constructor")                         \
  V(WrongEnumIndices, "wrong enum indices")                                    \
  V(WrongFeedbackCell, "wrong feedback cell")                                  \
  V(WrongInstanceType, "wrong instance type")                                  \
  V(WrongMap, "wrong map")                                                     \
  V(WrongMapDynamic, "map changed during operation")                           \
  V(WrongName, "wrong name")                                                   \
  V(WrongValue, "wrong value")

enum class DeoptimizeReason : uint8_t {
#define DEOPTIMIZE_REASON(Name, ...) k##Name,
  DEOPTIMIZE_REASON_LIST(DEOPTIMIZE_REASON)
#undef DEOPTIMIZE_REASON
};

#define LAZY_DEOPTIMIZE_REASON_LIST(V)                                        \
  V(MapDeprecated, "dependent map was deprecated")                            \
  V(PrototypeChange, "dependent prototype chain changed")                     \
  V(PropertyCellChange, "dependent property cell changed")                    \
  V(FieldTypeConstChange, "dependent field type constness changed")           \
  V(FieldTypeChange, "dependent field type changed")                          \
  V(FieldRepresentationChange, "dependent field representation changed")      \
  V(InitialMapChange, "dependent initial map changed")                        \
  V(AllocationSiteTenuringChange,                                             \
    "dependent allocation site tenuring changed")                             \
  V(AllocationSiteTransitionChange,                                           \
    "dependent allocation site transition changed")                           \
  V(ContextCellChange, "dependent context cell state changed")                \
  V(EmptyContextExtensionChange, "dependent empty context extension changed") \
  V(WeakObjects, "embedded weak objects cleared")                             \
  V(Debugger, "JS debugger attached")                                         \
  V(Testing, "for testing")                                                   \
  V(ExceptionCaught, "exception with omitted catch handler")                  \
  V(EagerDeopt, "marked due to eager deopt")                                  \
  V(FrameValueMaterialized, "value in stack frame was materialized")

enum class LazyDeoptimizeReason : uint8_t {
#define LAZY_DEOPTIMIZE_REASON(Name, message) k##Name,
  LAZY_DEOPTIMIZE_REASON_LIST(LAZY_DEOPTIMIZE_REASON)
#undef LAZY_DEOPTIMIZE_REASON
};

constexpr DeoptimizeReason kFirstDeoptimizeReason =
    static_cast<DeoptimizeReason>(0);
#define SUM(...) +1
constexpr int kDeoptimizeReasonCount = 0 DEOPTIMIZE_REASON_LIST(SUM);
#undef SUM
constexpr DeoptimizeReason kLastDeoptimizeReason =
    static_cast<DeoptimizeReason>(kDeoptimizeReasonCount - 1);

V8_EXPORT_PRIVATE std::ostream& operator<<(std::ostream&, DeoptimizeReason);

size_t hash_value(DeoptimizeReason reason);

V8_EXPORT_PRIVATE char const* DeoptimizeReasonToString(DeoptimizeReason reason);
V8_EXPORT_PRIVATE char const* DeoptimizeReasonToString(
    LazyDeoptimizeReason reason);

constexpr bool IsDeoptimizationWithoutCodeInvalidation(
    DeoptimizeReason reason) {
  // Maglev OSRs into Turbofan by first deoptimizing in order to restore the
  // unoptimized frame layout. Since no actual assumptions in the Maglev code
  // object are violated, it (and any associated cached optimized code) should
  // not be invalidated s.t. we may reenter it in the future.
  return reason == DeoptimizeReason::kPrepareForOnStackReplacement ||
         reason == DeoptimizeReason::kOSREarlyExit;
}

constexpr bool AlwaysPreserveDeoptReason(DeoptimizeReason reason) {
  switch (reason) {
#define CASE(name, ...) case DeoptimizeReason::k##name:
    DEOPTIMIZE_IN_BUILTIN_REASON_LIST(CASE)
#undef CASE
    return true;
    default:
      return false;
  }
}

}  // namespace internal
}  // namespace v8

#endif  // V8_DEOPTIMIZER_DEOPTIMIZE_REASON_H_
