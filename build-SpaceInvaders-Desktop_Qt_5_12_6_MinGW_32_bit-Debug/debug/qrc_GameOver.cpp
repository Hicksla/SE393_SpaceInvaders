/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.12.6
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // D:/CodeRepos/SE393_SpaceInvaders/SpaceInvaders/Music/06 The Victors' Homecoming.wav
  
  
  
static const unsigned char qt_resource_data[5147800] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // GameOver
  0x0,0x8,
  0x8,0x3a,0x65,0x62,
  0x0,0x47,
  0x0,0x61,0x0,0x6d,0x0,0x65,0x0,0x4f,0x0,0x76,0x0,0x65,0x0,0x72,
    // Music
  0x0,0x5,
  0x0,0x54,0xc9,0xf3,
  0x0,0x4d,
  0x0,0x75,0x0,0x73,0x0,0x69,0x0,0x63,
    // 06 The Victors' Homecoming.wav
  0x0,0x1e,
  0x3,0xd,0x39,0x86,
  0x0,0x30,
  0x0,0x36,0x0,0x20,0x0,0x54,0x0,0x68,0x0,0x65,0x0,0x20,0x0,0x56,0x0,0x69,0x0,0x63,0x0,0x74,0x0,0x6f,0x0,0x72,0x0,0x73,0x0,0x27,0x0,0x20,0x0,0x48,
  0x0,0x6f,0x0,0x6d,0x0,0x65,0x0,0x63,0x0,0x6f,0x0,0x6d,0x0,0x69,0x0,0x6e,0x0,0x67,0x0,0x2e,0x0,0x77,0x0,0x61,0x0,0x76,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/GameOver
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/GameOver/Music
  0x0,0x0,0x0,0x16,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x3,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/GameOver/Music/06 The Victors' Homecoming.wav
  0x0,0x0,0x0,0x26,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x79,0x19,0x37,0x64,0x4f,

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

int QT_RCC_MANGLE_NAMESPACE(qInitResources_GameOver)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_GameOver)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_GameOver)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_GameOver)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_GameOver)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_GameOver)(); }
   } dummy;
}
