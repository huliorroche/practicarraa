//
// Generated file, do not edit! Created by opp_msgtool 6.0 from trama.msg.
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
#include "trama_m.h"

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

Register_Class(trama)

trama::trama(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

trama::trama(const trama& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

trama::~trama()
{
}

trama& trama::operator=(const trama& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void trama::copy(const trama& other)
{
    this->tipoMensaje = other.tipoMensaje;
    this->numSerie = other.numSerie;
    this->assignID = other.assignID;
    this->retardoEQ = other.retardoEQ;
    this->tamanoMapa = other.tamanoMapa;
    for (size_t i = 0; i < 128; i++) {
        this->AllocID[i] = other.AllocID[i];
    }
    for (size_t i = 0; i < 128; i++) {
        this->inicio[i] = other.inicio[i];
    }
    for (size_t i = 0; i < 128; i++) {
        this->fin[i] = other.fin[i];
    }
}

void trama::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->tipoMensaje);
    doParsimPacking(b,this->numSerie);
    doParsimPacking(b,this->assignID);
    doParsimPacking(b,this->retardoEQ);
    doParsimPacking(b,this->tamanoMapa);
    doParsimArrayPacking(b,this->AllocID,128);
    doParsimArrayPacking(b,this->inicio,128);
    doParsimArrayPacking(b,this->fin,128);
}

void trama::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->tipoMensaje);
    doParsimUnpacking(b,this->numSerie);
    doParsimUnpacking(b,this->assignID);
    doParsimUnpacking(b,this->retardoEQ);
    doParsimUnpacking(b,this->tamanoMapa);
    doParsimArrayUnpacking(b,this->AllocID,128);
    doParsimArrayUnpacking(b,this->inicio,128);
    doParsimArrayUnpacking(b,this->fin,128);
}

int trama::getTipoMensaje() const
{
    return this->tipoMensaje;
}

void trama::setTipoMensaje(int tipoMensaje)
{
    this->tipoMensaje = tipoMensaje;
}

int trama::getNumSerie() const
{
    return this->numSerie;
}

void trama::setNumSerie(int numSerie)
{
    this->numSerie = numSerie;
}

int trama::getAssignID() const
{
    return this->assignID;
}

void trama::setAssignID(int assignID)
{
    this->assignID = assignID;
}

double trama::getRetardoEQ() const
{
    return this->retardoEQ;
}

void trama::setRetardoEQ(double retardoEQ)
{
    this->retardoEQ = retardoEQ;
}

int trama::getTamanoMapa() const
{
    return this->tamanoMapa;
}

void trama::setTamanoMapa(int tamanoMapa)
{
    this->tamanoMapa = tamanoMapa;
}

size_t trama::getAllocIDArraySize() const
{
    return 128;
}

int trama::getAllocID(size_t k) const
{
    if (k >= 128) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)128, (unsigned long)k);
    return this->AllocID[k];
}

void trama::setAllocID(size_t k, int AllocID)
{
    if (k >= 128) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)128, (unsigned long)k);
    this->AllocID[k] = AllocID;
}

size_t trama::getInicioArraySize() const
{
    return 128;
}

int trama::getInicio(size_t k) const
{
    if (k >= 128) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)128, (unsigned long)k);
    return this->inicio[k];
}

void trama::setInicio(size_t k, int inicio)
{
    if (k >= 128) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)128, (unsigned long)k);
    this->inicio[k] = inicio;
}

size_t trama::getFinArraySize() const
{
    return 128;
}

int trama::getFin(size_t k) const
{
    if (k >= 128) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)128, (unsigned long)k);
    return this->fin[k];
}

void trama::setFin(size_t k, int fin)
{
    if (k >= 128) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)128, (unsigned long)k);
    this->fin[k] = fin;
}

class tramaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_tipoMensaje,
        FIELD_numSerie,
        FIELD_assignID,
        FIELD_retardoEQ,
        FIELD_tamanoMapa,
        FIELD_AllocID,
        FIELD_inicio,
        FIELD_fin,
    };
  public:
    tramaDescriptor();
    virtual ~tramaDescriptor();

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

Register_ClassDescriptor(tramaDescriptor)

tramaDescriptor::tramaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(trama)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

tramaDescriptor::~tramaDescriptor()
{
    delete[] propertyNames;
}

bool tramaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<trama *>(obj)!=nullptr;
}

const char **tramaDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *tramaDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int tramaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 8+base->getFieldCount() : 8;
}

unsigned int tramaDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,    // FIELD_assignID
        FD_ISEDITABLE,    // FIELD_retardoEQ
        FD_ISEDITABLE,    // FIELD_tamanoMapa
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_AllocID
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_inicio
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_fin
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *tramaDescriptor::getFieldName(int field) const
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
        "assignID",
        "retardoEQ",
        "tamanoMapa",
        "AllocID",
        "inicio",
        "fin",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int tramaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "tipoMensaje") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "numSerie") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "assignID") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "retardoEQ") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "tamanoMapa") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "AllocID") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "inicio") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "fin") == 0) return baseIndex + 7;
    return base ? base->findField(fieldName) : -1;
}

const char *tramaDescriptor::getFieldTypeString(int field) const
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
        "int",    // FIELD_assignID
        "double",    // FIELD_retardoEQ
        "int",    // FIELD_tamanoMapa
        "int",    // FIELD_AllocID
        "int",    // FIELD_inicio
        "int",    // FIELD_fin
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **tramaDescriptor::getFieldPropertyNames(int field) const
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

const char *tramaDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int tramaDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    trama *pp = omnetpp::fromAnyPtr<trama>(object); (void)pp;
    switch (field) {
        case FIELD_AllocID: return 128;
        case FIELD_inicio: return 128;
        case FIELD_fin: return 128;
        default: return 0;
    }
}

void tramaDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    trama *pp = omnetpp::fromAnyPtr<trama>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'trama'", field);
    }
}

const char *tramaDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    trama *pp = omnetpp::fromAnyPtr<trama>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string tramaDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    trama *pp = omnetpp::fromAnyPtr<trama>(object); (void)pp;
    switch (field) {
        case FIELD_tipoMensaje: return long2string(pp->getTipoMensaje());
        case FIELD_numSerie: return long2string(pp->getNumSerie());
        case FIELD_assignID: return long2string(pp->getAssignID());
        case FIELD_retardoEQ: return double2string(pp->getRetardoEQ());
        case FIELD_tamanoMapa: return long2string(pp->getTamanoMapa());
        case FIELD_AllocID: return long2string(pp->getAllocID(i));
        case FIELD_inicio: return long2string(pp->getInicio(i));
        case FIELD_fin: return long2string(pp->getFin(i));
        default: return "";
    }
}

void tramaDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    trama *pp = omnetpp::fromAnyPtr<trama>(object); (void)pp;
    switch (field) {
        case FIELD_tipoMensaje: pp->setTipoMensaje(string2long(value)); break;
        case FIELD_numSerie: pp->setNumSerie(string2long(value)); break;
        case FIELD_assignID: pp->setAssignID(string2long(value)); break;
        case FIELD_retardoEQ: pp->setRetardoEQ(string2double(value)); break;
        case FIELD_tamanoMapa: pp->setTamanoMapa(string2long(value)); break;
        case FIELD_AllocID: pp->setAllocID(i,string2long(value)); break;
        case FIELD_inicio: pp->setInicio(i,string2long(value)); break;
        case FIELD_fin: pp->setFin(i,string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'trama'", field);
    }
}

omnetpp::cValue tramaDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    trama *pp = omnetpp::fromAnyPtr<trama>(object); (void)pp;
    switch (field) {
        case FIELD_tipoMensaje: return pp->getTipoMensaje();
        case FIELD_numSerie: return pp->getNumSerie();
        case FIELD_assignID: return pp->getAssignID();
        case FIELD_retardoEQ: return pp->getRetardoEQ();
        case FIELD_tamanoMapa: return pp->getTamanoMapa();
        case FIELD_AllocID: return pp->getAllocID(i);
        case FIELD_inicio: return pp->getInicio(i);
        case FIELD_fin: return pp->getFin(i);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'trama' as cValue -- field index out of range?", field);
    }
}

void tramaDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    trama *pp = omnetpp::fromAnyPtr<trama>(object); (void)pp;
    switch (field) {
        case FIELD_tipoMensaje: pp->setTipoMensaje(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_numSerie: pp->setNumSerie(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_assignID: pp->setAssignID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_retardoEQ: pp->setRetardoEQ(value.doubleValue()); break;
        case FIELD_tamanoMapa: pp->setTamanoMapa(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_AllocID: pp->setAllocID(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_inicio: pp->setInicio(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_fin: pp->setFin(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'trama'", field);
    }
}

const char *tramaDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr tramaDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    trama *pp = omnetpp::fromAnyPtr<trama>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void tramaDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    trama *pp = omnetpp::fromAnyPtr<trama>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'trama'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

