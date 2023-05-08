//
// Generated file, do not edit! Created by opp_msgtool 6.0 from trama.msg.
//

#ifndef __TRAMA_M_H
#define __TRAMA_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class trama;
/**
 * Class generated from <tt>trama.msg:13</tt> by opp_msgtool.
 * <pre>
 * //
 * // ETSI de Telecomunicaci�n. Universidad de M�laga
 * // Titulaci�n: Grado en Ingenier�a Telem�tico
 * // Asignatura: Redes de Acceso
 * // Profesora: Mar�a Carmen Espa�a Boquera
 * //
 * // Modelo trama descendente
 * //
 * //
 * //Trama enviada desde la OLT hacia las ONT
 * //
 * packet trama
 * {
 *     int tipoMensaje = 0;
 *     // Los mensajes PLOAM pueden ser de los siguientes tipos:
 *     // SIN MENSAJE(0)
 *     // RANGING(1)
 *     // ASSIGN_ID (2)
 * 
 *     int numSerie;
 *    //N�mero de serie de la ONT destinaaria del mensaje
 * 
 *     int assignID;
 *     //Valor de identificador asignado en mensajes ASSIGN_ID
 * 
 *     double retardoEQ;
 *    	//Cuando el mensaje es de tipo ASSIGN_ID, contiene el retardo de ecualizaci�n
 *    	//calculado por la OLT
 * 
 *     //Los siguientes campos conforman el mapa de la trama ascendente
 *     int tamanoMapa;
 *     int AllocID[128];//Identificador de la ONT a la cual se asigna el intervalo
 *     int inicio[128];//Inicio del intervalo
 *     int fin[128];//Fin del intervalo
 * 
 * 
 * }
 * </pre>
 */
class trama : public ::omnetpp::cPacket
{
  protected:
    int tipoMensaje = 0;
    int numSerie = 0;
    int assignID = 0;
    double retardoEQ = 0;
    int tamanoMapa = 0;
    int AllocID[128] = {0};
    int inicio[128] = {0};
    int fin[128] = {0};

  private:
    void copy(const trama& other);

  protected:
    bool operator==(const trama&) = delete;

  public:
    trama(const char *name=nullptr, short kind=0);
    trama(const trama& other);
    virtual ~trama();
    trama& operator=(const trama& other);
    virtual trama *dup() const override {return new trama(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getTipoMensaje() const;
    virtual void setTipoMensaje(int tipoMensaje);

    virtual int getNumSerie() const;
    virtual void setNumSerie(int numSerie);

    virtual int getAssignID() const;
    virtual void setAssignID(int assignID);

    virtual double getRetardoEQ() const;
    virtual void setRetardoEQ(double retardoEQ);

    virtual int getTamanoMapa() const;
    virtual void setTamanoMapa(int tamanoMapa);

    virtual size_t getAllocIDArraySize() const;
    virtual int getAllocID(size_t k) const;
    virtual void setAllocID(size_t k, int AllocID);

    virtual size_t getInicioArraySize() const;
    virtual int getInicio(size_t k) const;
    virtual void setInicio(size_t k, int inicio);

    virtual size_t getFinArraySize() const;
    virtual int getFin(size_t k) const;
    virtual void setFin(size_t k, int fin);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const trama& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, trama& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline trama *fromAnyPtr(any_ptr ptr) { return check_and_cast<trama*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __TRAMA_M_H
