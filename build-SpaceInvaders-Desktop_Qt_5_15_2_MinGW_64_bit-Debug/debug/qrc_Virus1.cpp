/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.15.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // C:/Users/EWann/Documents/trine/sp21/se393/project4_space_invaders/SE393_SpaceInvaders/SpaceInvaders/images/virus1.png
  0x0,0x0,0x0,0xb2,
  0x89,
  0x50,0x4e,0x47,0xd,0xa,0x1a,0xa,0x0,0x0,0x0,0xd,0x49,0x48,0x44,0x52,0x0,
  0x0,0x0,0x14,0x0,0x0,0x0,0x14,0x8,0x6,0x0,0x0,0x0,0x8d,0x89,0x1d,0xd,
  0x0,0x0,0x0,0x79,0x49,0x44,0x41,0x54,0x78,0xda,0x63,0x60,0x18,0x8,0x10,0xdc,
  0x23,0xf5,0x9f,0xaa,0x86,0x95,0xaf,0x55,0xf8,0x4f,0x35,0x43,0xa9,0x6a,0x20,0xb2,
  0x61,0x54,0x31,0x14,0x64,0xc0,0xe2,0x73,0xea,0x60,0xc3,0x40,0x34,0xd5,0x5c,0x49,
  0x35,0xc3,0x68,0x12,0xcb,0x14,0x1b,0x88,0xae,0x19,0x57,0x84,0x10,0x65,0x89,0x69,
  0x8e,0xc8,0x7f,0x64,0x1a,0x66,0x18,0xc,0xc3,0xc,0x41,0x57,0x87,0xd7,0x30,0x64,
  0x3e,0xb6,0x58,0xc6,0xa6,0xe,0xaf,0x61,0x20,0x4d,0xc8,0xde,0x81,0xf1,0xb1,0x89,
  0xe1,0x34,0x14,0x9b,0x17,0x40,0x6c,0x6c,0xae,0x41,0x57,0x43,0xb4,0x81,0xc4,0x0,
  0x82,0xfa,0xc8,0x35,0x90,0x7c,0x5,0x14,0xaa,0x1f,0xa6,0x0,0x0,0xfa,0x70,0x88,
  0xf2,0x17,0xb4,0x85,0xc4,0x0,0x0,0x0,0x0,0x49,0x45,0x4e,0x44,0xae,0x42,0x60,
  0x82,
  
};

static const unsigned char qt_resource_name[] = {
  // images
  0x0,0x6,
  0x7,0x3,0x7d,0xc3,
  0x0,0x69,
  0x0,0x6d,0x0,0x61,0x0,0x67,0x0,0x65,0x0,0x73,
    // virus1.png
  0x0,0xa,
  0xc,0x6f,0xf6,0x67,
  0x0,0x76,
  0x0,0x69,0x0,0x72,0x0,0x75,0x0,0x73,0x0,0x31,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/images
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/images/virus1.png
  0x0,0x0,0x0,0x12,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x78,0xd6,0x3d,0x2d,0xb1,

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

int QT_RCC_MANGLE_NAMESPACE(qInitResources_Virus1)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_Virus1)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_Virus1)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_Virus1)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_Virus1)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_Virus1)(); }
   } dummy;
}
