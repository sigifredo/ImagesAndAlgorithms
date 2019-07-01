

#ifndef PAINTIMAGEHELPER_HPP
#define PAINTIMAGEHELPER_HPP

// Own
#include <PaintHelperInterface.hpp>

class PaintImageHelper: public PaintHelperInterface
{
    Q_OBJECT
public:
    PaintImageHelper(QObject * pParent = nullptr);
    ~PaintImageHelper();

    /**
     * Método encargado de pintar las partículas en la pantalla.
     *
     * @param pPainter Puntero a QPainter, objeto encargado de pintar los diferentes elementos de la pantalla.
     * @param pEvent Puntero al manejador del evento.
     *
     */
    void paint(QPainter* pPainter, QPaintEvent* pEvent) override;

    /**
     * Método encargado de leer la lista de partículas desde una imagen,
     *
     * @param sImagePath Ruta de la imagen de la cual se tomarán las partículas.
     *
     */
    void readImage(const QString& sImagePath);

private:
    QImage * _pImage;
};

#endif
