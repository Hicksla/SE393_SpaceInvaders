/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.15.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // C:/Users/EWann/Documents/trine/sp21/se393/project4_space_invaders/SE393_SpaceInvaders/SpaceInvaders/Music/laser2.wav
  
  
  
static const unsigned char qt_resource_data[46648] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // laser2
  0x0,0x6,
  0x7,0x28,0x9c,0x52,
  0x0,0x6c,
  0x0,0x61,0x0,0x73,0x0,0x65,0x0,0x72,0x0,0x32,
    // Music
  0x0,0x5,
  0x0,0x54,0xc9,0xf3,
  0x0,0x4d,
  0x0,0x75,0x0,0x73,0x0,0x69,0x0,0x63,
    // laser2.wav
  0x0,0xa,
  0xc,0x5b,0xc,0xa6,
  0x0,0x6c,
  0x0,0x61,0x0,0x73,0x0,0x65,0x0,0x72,0x0,0x32,0x0,0x2e,0x0,0x77,0x0,0x61,0x0,0x76,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/laser2
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/laser2/Music
  0x0,0x0,0x0,0x12,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x3,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/laser2/Music/laser2.wav
  0x0,0x0,0x0,0x22,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x79,0x9,0x70,0x47,0xb7,

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

int QT_RCC_MANGLE_NAMESPACE(qInitResources_laser2)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_laser2)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_laser2)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_laser2)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_laser2)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_laser2)(); }
   } dummy;
}
