/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.12.6
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // D:/CodeRepos/SE393_SpaceInvaders/SpaceInvaders/Music/atari_boom5.wav
  
  
  
static const unsigned char qt_resource_data[121200] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // playerExplosion
  0x0,0xf,
  0x6,0xcf,0x9d,0x1e,
  0x0,0x70,
  0x0,0x6c,0x0,0x61,0x0,0x79,0x0,0x65,0x0,0x72,0x0,0x45,0x0,0x78,0x0,0x70,0x0,0x6c,0x0,0x6f,0x0,0x73,0x0,0x69,0x0,0x6f,0x0,0x6e,
    // Music
  0x0,0x5,
  0x0,0x54,0xc9,0xf3,
  0x0,0x4d,
  0x0,0x75,0x0,0x73,0x0,0x69,0x0,0x63,
    // atari_boom5.wav
  0x0,0xf,
  0x7,0x1b,0x4d,0xe6,
  0x0,0x61,
  0x0,0x74,0x0,0x61,0x0,0x72,0x0,0x69,0x0,0x5f,0x0,0x62,0x0,0x6f,0x0,0x6f,0x0,0x6d,0x0,0x35,0x0,0x2e,0x0,0x77,0x0,0x61,0x0,0x76,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/playerExplosion
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/playerExplosion/Music
  0x0,0x0,0x0,0x24,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x3,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/playerExplosion/Music/atari_boom5.wav
  0x0,0x0,0x0,0x34,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x79,0x19,0x37,0x64,0x87,

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

int QT_RCC_MANGLE_NAMESPACE(qInitResources_playerExplosion)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_playerExplosion)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_playerExplosion)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_playerExplosion)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_playerExplosion)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_playerExplosion)(); }
   } dummy;
}
