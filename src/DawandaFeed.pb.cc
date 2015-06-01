// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DawandaFeed.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "DawandaFeed.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* SessionFeed_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SessionFeed_reflection_ = NULL;
const ::google::protobuf::Descriptor* QueryFeed_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  QueryFeed_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_DawandaFeed_2eproto() {
  protobuf_AddDesc_DawandaFeed_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "DawandaFeed.proto");
  GOOGLE_CHECK(file != NULL);
  SessionFeed_descriptor_ = file->message_type(0);
  static const int SessionFeed_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SessionFeed, session_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SessionFeed, visited_products_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SessionFeed, bought_products_),
  };
  SessionFeed_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SessionFeed_descriptor_,
      SessionFeed::default_instance_,
      SessionFeed_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SessionFeed, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SessionFeed, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SessionFeed));
  QueryFeed_descriptor_ = file->message_type(1);
  static const int QueryFeed_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryFeed, session_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryFeed, product_list_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryFeed, clicked_products_),
  };
  QueryFeed_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      QueryFeed_descriptor_,
      QueryFeed::default_instance_,
      QueryFeed_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryFeed, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryFeed, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(QueryFeed));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_DawandaFeed_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SessionFeed_descriptor_, &SessionFeed::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    QueryFeed_descriptor_, &QueryFeed::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_DawandaFeed_2eproto() {
  delete SessionFeed::default_instance_;
  delete SessionFeed_reflection_;
  delete QueryFeed::default_instance_;
  delete QueryFeed_reflection_;
}

void protobuf_AddDesc_DawandaFeed_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021DawandaFeed.proto\"T\n\013SessionFeed\022\022\n\nse"
    "ssion_id\030\001 \002(\t\022\030\n\020visited_products\030\002 \003(\t"
    "\022\027\n\017bought_products\030\003 \003(\t\"O\n\tQueryFeed\022\022"
    "\n\nsession_id\030\001 \002(\t\022\024\n\014product_list\030\002 \003(\t"
    "\022\030\n\020clicked_products\030\003 \003(\t", 186);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "DawandaFeed.proto", &protobuf_RegisterTypes);
  SessionFeed::default_instance_ = new SessionFeed();
  QueryFeed::default_instance_ = new QueryFeed();
  SessionFeed::default_instance_->InitAsDefaultInstance();
  QueryFeed::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_DawandaFeed_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_DawandaFeed_2eproto {
  StaticDescriptorInitializer_DawandaFeed_2eproto() {
    protobuf_AddDesc_DawandaFeed_2eproto();
  }
} static_descriptor_initializer_DawandaFeed_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int SessionFeed::kSessionIdFieldNumber;
const int SessionFeed::kVisitedProductsFieldNumber;
const int SessionFeed::kBoughtProductsFieldNumber;
#endif  // !_MSC_VER

SessionFeed::SessionFeed()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:SessionFeed)
}

void SessionFeed::InitAsDefaultInstance() {
}

SessionFeed::SessionFeed(const SessionFeed& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:SessionFeed)
}

void SessionFeed::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  session_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SessionFeed::~SessionFeed() {
  // @@protoc_insertion_point(destructor:SessionFeed)
  SharedDtor();
}

void SessionFeed::SharedDtor() {
  if (session_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete session_id_;
  }
  if (this != default_instance_) {
  }
}

void SessionFeed::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SessionFeed::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SessionFeed_descriptor_;
}

const SessionFeed& SessionFeed::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_DawandaFeed_2eproto();
  return *default_instance_;
}

SessionFeed* SessionFeed::default_instance_ = NULL;

SessionFeed* SessionFeed::New() const {
  return new SessionFeed;
}

void SessionFeed::Clear() {
  if (has_session_id()) {
    if (session_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      session_id_->clear();
    }
  }
  visited_products_.Clear();
  bought_products_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SessionFeed::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SessionFeed)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string session_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_session_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->session_id().data(), this->session_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "session_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_visited_products;
        break;
      }

      // repeated string visited_products = 2;
      case 2: {
        if (tag == 18) {
         parse_visited_products:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_visited_products()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->visited_products(this->visited_products_size() - 1).data(),
            this->visited_products(this->visited_products_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "visited_products");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_visited_products;
        if (input->ExpectTag(26)) goto parse_bought_products;
        break;
      }

      // repeated string bought_products = 3;
      case 3: {
        if (tag == 26) {
         parse_bought_products:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_bought_products()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->bought_products(this->bought_products_size() - 1).data(),
            this->bought_products(this->bought_products_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "bought_products");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_bought_products;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SessionFeed)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SessionFeed)
  return false;
#undef DO_
}

void SessionFeed::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SessionFeed)
  // required string session_id = 1;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->session_id().data(), this->session_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "session_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->session_id(), output);
  }

  // repeated string visited_products = 2;
  for (int i = 0; i < this->visited_products_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
    this->visited_products(i).data(), this->visited_products(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE,
    "visited_products");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->visited_products(i), output);
  }

  // repeated string bought_products = 3;
  for (int i = 0; i < this->bought_products_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
    this->bought_products(i).data(), this->bought_products(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE,
    "bought_products");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->bought_products(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:SessionFeed)
}

::google::protobuf::uint8* SessionFeed::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:SessionFeed)
  // required string session_id = 1;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->session_id().data(), this->session_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "session_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->session_id(), target);
  }

  // repeated string visited_products = 2;
  for (int i = 0; i < this->visited_products_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->visited_products(i).data(), this->visited_products(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "visited_products");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(2, this->visited_products(i), target);
  }

  // repeated string bought_products = 3;
  for (int i = 0; i < this->bought_products_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->bought_products(i).data(), this->bought_products(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "bought_products");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(3, this->bought_products(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SessionFeed)
  return target;
}

int SessionFeed::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string session_id = 1;
    if (has_session_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->session_id());
    }

  }
  // repeated string visited_products = 2;
  total_size += 1 * this->visited_products_size();
  for (int i = 0; i < this->visited_products_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->visited_products(i));
  }

  // repeated string bought_products = 3;
  total_size += 1 * this->bought_products_size();
  for (int i = 0; i < this->bought_products_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->bought_products(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SessionFeed::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SessionFeed* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SessionFeed*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SessionFeed::MergeFrom(const SessionFeed& from) {
  GOOGLE_CHECK_NE(&from, this);
  visited_products_.MergeFrom(from.visited_products_);
  bought_products_.MergeFrom(from.bought_products_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_session_id()) {
      set_session_id(from.session_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SessionFeed::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SessionFeed::CopyFrom(const SessionFeed& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SessionFeed::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void SessionFeed::Swap(SessionFeed* other) {
  if (other != this) {
    std::swap(session_id_, other->session_id_);
    visited_products_.Swap(&other->visited_products_);
    bought_products_.Swap(&other->bought_products_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SessionFeed::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SessionFeed_descriptor_;
  metadata.reflection = SessionFeed_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int QueryFeed::kSessionIdFieldNumber;
const int QueryFeed::kProductListFieldNumber;
const int QueryFeed::kClickedProductsFieldNumber;
#endif  // !_MSC_VER

QueryFeed::QueryFeed()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:QueryFeed)
}

void QueryFeed::InitAsDefaultInstance() {
}

QueryFeed::QueryFeed(const QueryFeed& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:QueryFeed)
}

void QueryFeed::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  session_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

QueryFeed::~QueryFeed() {
  // @@protoc_insertion_point(destructor:QueryFeed)
  SharedDtor();
}

void QueryFeed::SharedDtor() {
  if (session_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete session_id_;
  }
  if (this != default_instance_) {
  }
}

void QueryFeed::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* QueryFeed::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return QueryFeed_descriptor_;
}

const QueryFeed& QueryFeed::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_DawandaFeed_2eproto();
  return *default_instance_;
}

QueryFeed* QueryFeed::default_instance_ = NULL;

QueryFeed* QueryFeed::New() const {
  return new QueryFeed;
}

void QueryFeed::Clear() {
  if (has_session_id()) {
    if (session_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      session_id_->clear();
    }
  }
  product_list_.Clear();
  clicked_products_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool QueryFeed::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:QueryFeed)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string session_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_session_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->session_id().data(), this->session_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "session_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_product_list;
        break;
      }

      // repeated string product_list = 2;
      case 2: {
        if (tag == 18) {
         parse_product_list:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_product_list()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->product_list(this->product_list_size() - 1).data(),
            this->product_list(this->product_list_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "product_list");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_product_list;
        if (input->ExpectTag(26)) goto parse_clicked_products;
        break;
      }

      // repeated string clicked_products = 3;
      case 3: {
        if (tag == 26) {
         parse_clicked_products:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_clicked_products()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->clicked_products(this->clicked_products_size() - 1).data(),
            this->clicked_products(this->clicked_products_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "clicked_products");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_clicked_products;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:QueryFeed)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:QueryFeed)
  return false;
#undef DO_
}

void QueryFeed::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:QueryFeed)
  // required string session_id = 1;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->session_id().data(), this->session_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "session_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->session_id(), output);
  }

  // repeated string product_list = 2;
  for (int i = 0; i < this->product_list_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
    this->product_list(i).data(), this->product_list(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE,
    "product_list");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->product_list(i), output);
  }

  // repeated string clicked_products = 3;
  for (int i = 0; i < this->clicked_products_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
    this->clicked_products(i).data(), this->clicked_products(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE,
    "clicked_products");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->clicked_products(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:QueryFeed)
}

::google::protobuf::uint8* QueryFeed::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:QueryFeed)
  // required string session_id = 1;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->session_id().data(), this->session_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "session_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->session_id(), target);
  }

  // repeated string product_list = 2;
  for (int i = 0; i < this->product_list_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->product_list(i).data(), this->product_list(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "product_list");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(2, this->product_list(i), target);
  }

  // repeated string clicked_products = 3;
  for (int i = 0; i < this->clicked_products_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->clicked_products(i).data(), this->clicked_products(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "clicked_products");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(3, this->clicked_products(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:QueryFeed)
  return target;
}

int QueryFeed::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string session_id = 1;
    if (has_session_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->session_id());
    }

  }
  // repeated string product_list = 2;
  total_size += 1 * this->product_list_size();
  for (int i = 0; i < this->product_list_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->product_list(i));
  }

  // repeated string clicked_products = 3;
  total_size += 1 * this->clicked_products_size();
  for (int i = 0; i < this->clicked_products_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->clicked_products(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void QueryFeed::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const QueryFeed* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const QueryFeed*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void QueryFeed::MergeFrom(const QueryFeed& from) {
  GOOGLE_CHECK_NE(&from, this);
  product_list_.MergeFrom(from.product_list_);
  clicked_products_.MergeFrom(from.clicked_products_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_session_id()) {
      set_session_id(from.session_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void QueryFeed::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void QueryFeed::CopyFrom(const QueryFeed& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool QueryFeed::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void QueryFeed::Swap(QueryFeed* other) {
  if (other != this) {
    std::swap(session_id_, other->session_id_);
    product_list_.Swap(&other->product_list_);
    clicked_products_.Swap(&other->clicked_products_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata QueryFeed::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = QueryFeed_descriptor_;
  metadata.reflection = QueryFeed_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
