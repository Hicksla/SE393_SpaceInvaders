/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.15.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // C:/Users/EWann/Documents/trine/sp21/se393/project4_space_invaders/SE393_SpaceInvaders/SpaceInvaders/Music/explosion.wav
  
  
  
static const unsigned char qt_resource_data[53888] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // explosion
  0x0,0x9,
  0x7,0x36,0x49,0xbe,
  0x0,0x65,
  0x0,0x78,0x0,0x70,0x0,0x6c,0x0,0x6f,0x0,0x73,0x0,0x69,0x0,0x6f,0x0,0x6e,
    // Music
  0x0,0x5,
  0x0,0x54,0xc9,0xf3,
  0x0,0x4d,
  0x0,0x75,0x0,0x73,0x0,0x69,0x0,0x63,
    // explosion.wav
  0x0,0xd,
  0x9,0xcf,0x31,0x6,
  0x0,0x65,
  0x0,0x78,0x0,0x70,0x0,0x6c,0x0,0x6f,0x0,0x73,0x0,0x69,0x0,0x6f,0x0,0x6e,0x0,0x2e,0x0,0x77,0x0,0x61,0x0,0x76,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/explosion
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/explosion/Music
  0x0,0x0,0x0,0x18,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x3,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/explosion/Music/explosion.wav
  0x0,0x0,0x0,0x28,0x0,0x1,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x79,0x9,0x70,0x47,0xb3,

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

#if defined(__ELF__) || defined(__APPLE__)
static inline unsigned char qResourceFeatureZlib()
{
    extern const unsigned char qt_resourceFeatureZlib;
    return qt_resourceFeatureZlib;
}
#else
unsigned char qResourceFeatureZlib();
#endif

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_explosion)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_explosion)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_explosion)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_explosion)()
{
    int version = 3;
    version += QT_RCC_PREPEND_NAMESPACE(qResourceFeatureZlib());
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_explosion)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_explosion)(); }
   } dummy;
}
