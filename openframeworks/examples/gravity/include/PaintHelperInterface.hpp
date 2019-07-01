

#ifndef PAINTHELPERINTERFACE_HPP
#define PAINTHELPERINTERFACE_HPP

// Qt
#include <QPainter>
#include <QPaintEvent>

class PaintHelperInterface: public QObject
{
    Q_OBJECT
public:
    PaintHelperInterface(QObject * pParent = nullptr): QObject(pParent) { }

    /**
     * Método encargado de pintar las partículas en la pantalla.
     *
     * @param pPainter Puntero a QPainter, objeto encargado de pintar los diferentes elementos de la pantalla.
     * @param pEvent Puntero al manejador del evento.
     *
     */
    virtual void paint(QPainter* pPainter, QPaintEvent* pEvent) = 0;
};

#endif
