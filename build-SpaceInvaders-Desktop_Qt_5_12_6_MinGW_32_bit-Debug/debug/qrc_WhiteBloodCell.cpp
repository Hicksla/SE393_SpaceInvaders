/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.12.6
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // D:/CodeRepos/SE393_SpaceInvaders/SpaceInvaders/images/whitebloodcell.png
  
  
  
static const unsigned char qt_resource_data[247] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // images
  0x0,0x6,
  0x7,0x3,0x7d,0xc3,
  0x0,0x69,
  0x0,0x6d,0x0,0x61,0x0,0x67,0x0,0x65,0x0,0x73,
    // whitebloodcell.png
  0x0,0x12,
  0x9,0x37,0xc8,0xa7,
  0x0,0x77,
  0x0,0x68,0x0,0x69,0x0,0x74,0x0,0x65,0x0,0x62,0x0,0x6c,0x0,0x6f,0x0,0x6f,0x0,0x64,0x0,0x63,0x0,0x65,0x0,0x6c,0x0,0x6c,0x0,0x2e,0x0,0x70,0x0,0x6e,
  0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/images
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/images/whitebloodcell.png
  0x0,0x0,0x0,0x12,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x79,0x19,0x37,0x64,0xcc,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_WhiteBloodCell)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_WhiteBloodCell)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_WhiteBloodCell)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_WhiteBloodCell)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_WhiteBloodCell)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_WhiteBloodCell)(); }
   } dummy;
}
