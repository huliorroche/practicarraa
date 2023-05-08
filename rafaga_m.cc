//
// Generated file, do not edit! Created by opp_msgtool 6.0 from rafaga.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "rafaga_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(rafaga)

rafaga::rafaga(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

rafaga::rafaga(const rafaga& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

rafaga::~rafaga()
{
}

rafaga& rafaga::operator=(const rafaga& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void rafaga::copy(const rafaga& other)
{
    this->tipoMensaje = other.tipoMensaje;
    this->numSerie = other.numSerie;
    this->IdONT = other.IdONT;
    this->BWReport = other.BWReport;
    this->tipoTrafico = other.tipoTrafico;
}

void rafaga::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->tipoMensaje);
    doParsimPacking(b,this->numSerie);
    doParsimPacking(b,this->IdONT);
    doParsimPacking(b,this->BWReport);
    doParsimPacking(b,this->tipoTrafico);
}

void rafaga::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->tipoMensaje);
    doParsimUnpacking(b,this->numSerie);
    doParsimUnpacking(b,this->IdONT);
    doParsimUnpacking(b,this->BWReport);
    doParsimUnpacking(b,this->tipoTrafico);
}

int rafaga::getTipoMensaje() const
{
    return this->tipoMensaje;
}

void rafaga::setTipoMensaje(int tipoMensaje)
{
    this->tipoMensaje = tipoMensaje;
}

int rafaga::getNumSerie() const
{
    return this->numSerie;
}

void rafaga::setNumSerie(int numSerie)
{
    this->numSerie = numSerie;
}

int rafaga::getIdONT() const
{
    return this->IdONT;
}

void rafaga::setIdONT(int IdONT)
{
    this->IdONT = IdONT;
}

int rafaga::getBWReport() const
{
    return this->BWReport;
}

void rafaga::setBWReport(int BWReport)
{
    this->BWReport = BWReport;
}

int rafaga::getTipoTrafico() const
{
    return this->tipoTrafico;
}

void rafaga::setTipoTrafico(int tipoTrafico)
{
    this->tipoTrafico = tipoTrafico;
}

class rafagaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_tipoMensaje,
        FIELD_numSerie,
        FIELD_IdONT,
        FIELD_BWReport,
        FIELD_tipoTrafico,
    };
  public:
    rafagaDescriptor();
    virtual ~rafagaDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(rafagaDescriptor)

rafagaDescriptor::rafagaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(rafaga)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

rafagaDescriptor::~rafagaDescriptor()
{
    delete[] propertyNames;
}

bool rafagaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<rafaga *>(obj)!=nullptr;
}

const char **rafagaDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *rafagaDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int rafagaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int rafagaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_tipoMensaje
        FD_ISEDITABLE,    // FIELD_numSerie
        FD_ISEDITABLE,    // FIELD_IdONT
        FD_ISEDITABLE,    // FIELD_BWReport
        FD_ISEDITABLE,    // FIELD_tipoTrafico
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *rafagaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tipoMensaje",
        "numSerie",
        "IdONT",
        "BWReport",
        "tipoTrafico",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int rafagaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "tipoMensaje") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "numSerie") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "IdONT") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "BWReport") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "tipoTrafico") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *rafagaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_tipoMensaje
        "int",    // FIELD_numSerie
        "int",    // FIELD_IdONT
        "int",    // FIELD_BWReport
        "int",    // FIELD_tipoTrafico
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **rafagaDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *rafagaDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int rafagaDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    rafaga *pp = omnetpp::fromAnyPtr<rafaga>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void rafagaDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    rafaga *pp = omnetpp::fromAnyPtr<rafaga>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'rafaga'", field);
    }
}

const char *rafagaDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    rafaga *pp = omnetpp::fromAnyPtr<rafaga>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string rafagaDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    rafaga *pp = omnetpp::fromAnyPtr<rafaga>(object); (void)pp;
    switch (field) {
        case FIELD_tipoMensaje: return long2string(pp->getTipoMensaje());
        case FIELD_numSerie: return long2string(pp->getNumSerie());
        case FIELD_IdONT: return long2string(pp->getIdONT());
        case FIELD_BWReport: return long2string(pp->getBWReport());
        case FIELD_tipoTrafico: return long2string(pp->getTipoTrafico());
        default: return "";
    }
}

void rafagaDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    rafaga *pp = omnetpp::fromAnyPtr<rafaga>(object); (void)pp;
    switch (field) {
        case FIELD_tipoMensaje: pp->setTipoMensaje(string2long(value)); break;
        case FIELD_numSerie: pp->setNumSerie(string2long(value)); break;
        case FIELD_IdONT: pp->setIdONT(string2long(value)); break;
        case FIELD_BWReport: pp->setBWReport(string2long(value)); break;
        case FIELD_tipoTrafico: pp->setTipoTrafico(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'rafaga'", field);
    }
}

omnetpp::cValue rafagaDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    rafaga *pp = omnetpp::fromAnyPtr<rafaga>(object); (void)pp;
    switch (field) {
        case FIELD_tipoMensaje: return pp->getTipoMensaje();
        case FIELD_numSerie: return pp->getNumSerie();
        case FIELD_IdONT: return pp->getIdONT();
        case FIELD_BWReport: return pp->getBWReport();
        case FIELD_tipoTrafico: return pp->getTipoTrafico();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'rafaga' as cValue -- field index out of range?", field);
    }
}

void rafagaDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    rafaga *pp = omnetpp::fromAnyPtr<rafaga>(object); (void)pp;
    switch (field) {
        case FIELD_tipoMensaje: pp->setTipoMensaje(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_numSerie: pp->setNumSerie(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_IdONT: pp->setIdONT(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_BWReport: pp->setBWReport(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_tipoTrafico: pp->setTipoTrafico(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'rafaga'", field);
    }
}

const char *rafagaDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr rafagaDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    rafaga *pp = omnetpp::fromAnyPtr<rafaga>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void rafagaDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    rafaga *pp = omnetpp::fromAnyPtr<rafaga>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'rafaga'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

