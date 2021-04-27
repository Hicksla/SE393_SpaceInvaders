/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.15.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // C:/Users/EWann/Documents/trine/sp21/se393/project4_space_invaders/SE393_SpaceInvaders/SpaceInvaders/Music/laser.wav
  
  
  
static const unsigned char qt_resource_data[194204] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // laser
  0x0,0x5,
  0x0,0x72,0x89,0xc2,
  0x0,0x6c,
  0x0,0x61,0x0,0x73,0x0,0x65,0x0,0x72,
    // Music
  0x0,0x5,
  0x0,0x54,0xc9,0xf3,
  0x0,0x4d,
  0x0,0x75,0x0,0x73,0x0,0x69,0x0,0x63,
    // laser.wav
  0x0,0x9,
  0x9,0xc5,0xb8,0x86,
  0x0,0x6c,
  0x0,0x61,0x0,0x73,0x0,0x65,0x0,0x72,0x0,0x2e,0x0,0x77,0x0,0x61,0x0,0x76,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/laser
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/laser/Music
  0x0,0x0,0x0,0x10,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x3,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/laser/Music/laser.wav
  0x0,0x0,0x0,0x20,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x79,0x9,0x70,0x47,0xb6,

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

int QT_RCC_MANGLE_NAMESPACE(qInitResources_laser)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_laser)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_laser)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_laser)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_laser)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_laser)(); }
   } dummy;
}
