

// Own
#include <PaintImageHelper.hpp>

// utils
#include <utils/IOStream.hpp>

#define STOUT_CLASS             "\e[94m[PaintImageHelper]\e[39m "
#define STERR_CLASS             "\e[91m[PaintImageHelper]\e[39m "

PaintImageHelper::PaintImageHelper(QObject * pParent):
    PaintHelperInterface(pParent)
{
    _pImage = nullptr;
}

PaintImageHelper::~PaintImageHelper()
{
    if (_pImage)
    {
        delete _pImage;
    }
}

void PaintImageHelper::paint(QPainter* pPainter, QPaintEvent* pEvent)
{
}

void PaintImageHelper::readImage(const QString& sImagePath)
{
    QImage oImage;

    if (oImage.load(sImagePath))
    {
        if (_pImage)
        {
            delete _pImage;
        }

        _pImage = new QImage(oImage);
    }
    else
    {
        std::cerr << STERR_CLASS "No se ha podido leer la imagen (" << sImagePath << ")." << std::endl;
    }
}
