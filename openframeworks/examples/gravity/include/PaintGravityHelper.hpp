

#ifndef PAINTHELPER_HPP
#define PAINTHELPER_HPP

// Own
#include <PaintHelperInterface.hpp>
#include <Particle.hpp>

// Qt
#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class PaintGravityHelper: public PaintHelperInterface
{
    Q_OBJECT
public:
    PaintGravityHelper(QObject * pParent = nullptr);

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
     * @param iParticleSize Tamaño de cada partícula.
     *
     */
    void readImage(const QString& sImagePath, const int& iParticleSize = 5);

    /**
     * Método encargado de leer la lista de partículas desde una imagen,
     *
     * @param sImagePath Ruta de la imagen de la cual se tomarán las partículas.
     * @param iParticleSize Tamaño de cada partícula.
     *
     */
    void readParticlesFromImage(const QString& sImagePath, const int& iParticleSize = 5);

protected:
    /**
     * Método encargado de simular la gravedad.
     *
     * @param pPainter Puntero a QPainter, objeto encargado de pintar los diferentes elementos de la pantalla.
     * @param pEvent Puntero al manejador del evento.
     *
     */
    void gravity(QPainter* pPainter, QPaintEvent* pEvent);

private:
    /**
     * Arreglo de las partículas que se encuentran en el sistema.
     */
    QList<Particle> _lParticles;
    /**
     * Pincel con el que se pinta el fondo.
     */
    QBrush _oBackground;
};

#endif
