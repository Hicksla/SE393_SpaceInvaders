/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.12.6
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // D:/CodeRepos/SE393_SpaceInvaders/SpaceInvaders/images/redbloodcell.png
  0x0,0x0,0x0,0x9e,
  0x89,
  0x50,0x4e,0x47,0xd,0xa,0x1a,0xa,0x0,0x0,0x0,0xd,0x49,0x48,0x44,0x52,0x0,
  0x0,0x0,0x14,0x0,0x0,0x0,0x14,0x8,0x6,0x0,0x0,0x0,0x8d,0x89,0x1d,0xd,
  0x0,0x0,0x0,0x65,0x49,0x44,0x41,0x54,0x78,0xda,0x63,0x60,0x18,0x5,0x83,0x17,
  0x94,0xa,0x9,0xfd,0x47,0xc6,0x14,0xa9,0x7,0x9,0xb4,0x49,0x48,0x82,0x25,0x16,
  0x28,0xaa,0x83,0x31,0x36,0xc5,0xc8,0x62,0xc8,0xea,0x60,0x7a,0x71,0x1a,0x86,0x8e,
  0xd1,0xd,0xc1,0x26,0xf,0x37,0x94,0x18,0x3,0x9,0x61,0xac,0x6,0xc2,0x4,0x48,
  0x31,0x18,0xa6,0x1e,0x59,0x3f,0x8a,0x81,0xe8,0x6,0x13,0xc2,0xd8,0xf4,0x61,0x35,
  0x90,0x5c,0x8c,0x11,0x31,0x54,0x31,0xc,0x5b,0x92,0x20,0xc5,0x10,0xa2,0xd2,0x2d,
  0xb1,0x61,0x38,0x5a,0x1c,0xc,0x11,0x0,0x0,0x81,0x1c,0x1f,0x6c,0xa4,0x85,0x29,
  0x22,0x0,0x0,0x0,0x0,0x49,0x45,0x4e,0x44,0xae,0x42,0x60,0x82,
  
};

static const unsigned char qt_resource_name[] = {
  // images
  0x0,0x6,
  0x7,0x3,0x7d,0xc3,
  0x0,0x69,
  0x0,0x6d,0x0,0x61,0x0,0x67,0x0,0x65,0x0,0x73,
    // redbloodcell.png
  0x0,0x10,
  0xa,0x55,0xcc,0xc7,
  0x0,0x72,
  0x0,0x65,0x0,0x64,0x0,0x62,0x0,0x6c,0x0,0x6f,0x0,0x6f,0x0,0x64,0x0,0x63,0x0,0x65,0x0,0x6c,0x0,0x6c,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/images
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/images/redbloodcell.png
  0x0,0x0,0x0,0x12,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x78,0xd4,0x6,0x81,0xf1,

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

int QT_RCC_MANGLE_NAMESPACE(qInitResources_RedBloodCell)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_RedBloodCell)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_RedBloodCell)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_RedBloodCell)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_RedBloodCell)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_RedBloodCell)(); }
   } dummy;
}