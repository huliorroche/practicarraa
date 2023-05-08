//
// Generated file, do not edit! Created by opp_msgtool 6.0 from rafaga.msg.
//

#ifndef __RAFAGA_M_H
#define __RAFAGA_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class rafaga;
/**
 * Class generated from <tt>rafaga.msg:11</tt> by opp_msgtool.
 * <pre>
 * packet rafaga
 * {
 *     int tipoMensaje = 0;
 *     // Los mensajes PLOAM pueden ser de los siguientes tipos:
 *     // SIN MENSAJE(0)
 *     // SERIAL NUMBER(1)
 *     int numSerie;
 *     //N�mero de serie de la ONT origen del mensaje
 *     int IdONT; //Identificador de la ONT
 *     int BWReport;//Informe sobre el estado de la cola
 *     int tipoTrafico; //La ONT informa a la OLT del tipo de tr�fico que generar� 
 * 					//Se incluye en mensajes SERIAL NUMBER
 * 
 * 
 * 
 * }
 * </pre>
 */
class rafaga : public ::omnetpp::cPacket
{
  protected:
    int tipoMensaje = 0;
    int numSerie = 0;
    int IdONT = 0;
    int BWReport = 0;
    int tipoTrafico = 0;

  private:
    void copy(const rafaga& other);

  protected:
    bool operator==(const rafaga&) = delete;

  public:
    rafaga(const char *name=nullptr, short kind=0);
    rafaga(const rafaga& other);
    virtual ~rafaga();
    rafaga& operator=(const rafaga& other);
    virtual rafaga *dup() const override {return new rafaga(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getTipoMensaje() const;
    virtual void setTipoMensaje(int tipoMensaje);

    virtual int getNumSerie() const;
    virtual void setNumSerie(int numSerie);

    virtual int getIdONT() const;
    virtual void setIdONT(int IdONT);

    virtual int getBWReport() const;
    virtual void setBWReport(int BWReport);

    virtual int getTipoTrafico() const;
    virtual void setTipoTrafico(int tipoTrafico);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const rafaga& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, rafaga& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline rafaga *fromAnyPtr(any_ptr ptr) { return check_and_cast<rafaga*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __RAFAGA_M_H
