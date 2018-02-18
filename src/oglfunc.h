#ifndef OGLFUNC_H
#define OGLFUNC_H

#if defined(_MSC_VER)
#include <windows.h>
#endif

#include "SDL_version.h"

#if defined(USE_OPENGL_ES)
#include "SDL_opengles2.h"

// OpenGL compatibility
typedef GLclampf GLclampd;
typedef GLfloat GLdouble;

#else
#include "SDL_opengl.h"
#endif

#if !defined(GL_CLAMP_TO_EDGE)
// Originally added by GL_SGIS_texture_edge_clamp; part of OpenGL 1.2 core.
#define GL_CLAMP_TO_EDGE 0x812F
#endif

#if !defined(APIENTRY)
#define APIENTRY
#endif

// Base OpenGL / OpenGL ES
typedef void (APIENTRY *avpPFNGLACTIVETEXTUREPROC)(GLenum);
typedef void (APIENTRY *avpPFNGLBINDTEXTUREPROC)(GLenum, GLuint);
typedef void (APIENTRY *avpPFNGLBLENDFUNCPROC)(GLenum, GLenum);
typedef void (APIENTRY *avpPFNGLCLEARPROC)(GLbitfield);
typedef void (APIENTRY *avpPFNGLCLEARCOLORPROC)(GLclampf, GLclampf, GLclampf, GLclampf);
typedef void (APIENTRY *avpPFNGLCULLFACEPROC)(GLenum);
typedef void (APIENTRY *avpPFNGLDELETETEXTURESPROC)(GLsizei,const GLuint*);
typedef void (APIENTRY *avpPFNGLDEPTHFUNCPROC)(GLenum);
typedef void (APIENTRY *avpPFNGLDEPTHMASKPROC)(GLboolean);
typedef void (APIENTRY *avpPFNGLDEPTHRANGEPROC)(GLclampd, GLclampd);
typedef void (APIENTRY *avpPFNGLDISABLEPROC)(GLenum);
typedef void (APIENTRY *avpPFNGLDRAWELEMENTSPROC)(GLenum, GLsizei, GLenum, const GLvoid *);
typedef void (APIENTRY *avpPFNGLENABLEPROC)(GLenum);
typedef void (APIENTRY *avpPFNGLFRONTFACEPROC)(GLenum);
typedef void (APIENTRY *avpPFNGLGENTEXTURESPROC)(GLsizei,GLuint*);
typedef GLenum (APIENTRY *avpPFNGLGETERRORPROC)(void);
typedef void (APIENTRY *avpPFNGLGETFLOATVPROC)(GLenum, GLfloat *);
typedef void (APIENTRY *avpPFNGLGETINTEGERVPROC)(GLenum, GLint *);
typedef const GLubyte* (APIENTRY *avpPFNGLGETSTRINGPROC)(GLenum);
typedef void (APIENTRY *avpPFNGLGETTEXPARAMETERFVPROC)(GLenum, GLenum, GLfloat*);
typedef void (APIENTRY *avpPFNGLHINTPROC)(GLenum, GLenum);
typedef void (APIENTRY *avpPFNGLPIXELSTOREIPROC)(GLenum, GLint);
typedef void (APIENTRY *avpPFNGLPOLYGONOFFSETPROC)(GLfloat, GLfloat);
typedef void (APIENTRY *avpPFNGLREADPIXELSPROC)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *);
typedef void (APIENTRY *avpPFNGLTEXIMAGE2DPROC)(GLenum,GLint,GLint,GLsizei,GLsizei,GLint,GLenum,GLenum,const GLvoid*);
typedef void (APIENTRY *avpPFNGLTEXPARAMETERFPROC)(GLenum, GLenum, GLfloat);
typedef void (APIENTRY *avpPFNGLTEXPARAMETERIPROC)(GLenum, GLenum, GLint);
typedef void (APIENTRY *avpPFNGLTEXSUBIMAGE2DPROC)(GLenum,GLint,GLint,GLint,GLsizei,GLsizei,GLenum,GLenum,const GLvoid*);
typedef void (APIENTRY *avpPFNGLVIEWPORTPROC)(GLint, GLint, GLsizei, GLsizei);

extern avpPFNGLACTIVETEXTUREPROC pglActiveTexture;
extern avpPFNGLBINDTEXTUREPROC		pglBindTexture;
extern avpPFNGLBLENDFUNCPROC		pglBlendFunc;
extern avpPFNGLCLEARPROC			pglClear;
extern avpPFNGLCLEARCOLORPROC		pglClearColor;
extern avpPFNGLCULLFACEPROC		pglCullFace;
extern avpPFNGLDELETETEXTURESPROC		pglDeleteTextures;
extern avpPFNGLDEPTHFUNCPROC		pglDepthFunc;
extern avpPFNGLDEPTHMASKPROC		pglDepthMask;
extern avpPFNGLDEPTHRANGEPROC		pglDepthRange;
extern avpPFNGLDISABLEPROC		pglDisable;
extern avpPFNGLDRAWELEMENTSPROC		pglDrawElements;
extern avpPFNGLENABLEPROC			pglEnable;
extern avpPFNGLFRONTFACEPROC		pglFrontFace;
extern avpPFNGLGENTEXTURESPROC		pglGenTextures;
extern avpPFNGLGETERRORPROC		pglGetError;
extern avpPFNGLGETFLOATVPROC		pglGetFloatv;
extern avpPFNGLGETINTEGERVPROC		pglGetIntegerv;
extern avpPFNGLGETSTRINGPROC		pglGetString;
extern avpPFNGLGETTEXPARAMETERFVPROC	pglGetTexParameterfv;
extern avpPFNGLHINTPROC			pglHint;
extern avpPFNGLPIXELSTOREIPROC		pglPixelStorei;
extern avpPFNGLPOLYGONOFFSETPROC		pglPolygonOffset;
extern avpPFNGLREADPIXELSPROC		pglReadPixels;
extern avpPFNGLTEXIMAGE2DPROC		pglTexImage2D;
extern avpPFNGLTEXPARAMETERFPROC		pglTexParameterf;
extern avpPFNGLTEXPARAMETERIPROC		pglTexParameteri;
extern avpPFNGLTEXSUBIMAGE2DPROC		pglTexSubImage2D;
extern avpPFNGLVIEWPORTPROC		pglViewport;

// OpenGL 2.1 / OpenGL ES 2.0
typedef void (APIENTRY *avpPFNGLATTACHSHADERPROC)(GLuint, GLuint);
typedef void (APIENTRY *avpPFNGLBINDATTRIBLOCATIONPROC)(GLuint, GLuint, const GLchar*);
typedef void (APIENTRY *avpPFNGLBINDBUFFERPROC)(GLenum, GLuint);
typedef void (APIENTRY *avpPFNGLBUFFERDATAPROC)(GLenum, GLsizeiptr, const GLvoid*, GLenum);
typedef void (APIENTRY *avpPFNGLBUFFERSUBDATAPROC)(GLenum, GLintptr, GLsizeiptr, const GLvoid*);
typedef GLuint (APIENTRY *avpPFNGLCREATEPROGRAMPROC)(void);
typedef GLuint (APIENTRY *avpPFNGLCREATESHADERPROC)(GLenum);
typedef void (APIENTRY *avpPFNGLCOMPILESHADERPROC)(GLuint);
typedef void (APIENTRY *avpPFNGLDELETEBUFFERSPROC)(GLsizei, const GLuint*);
typedef void (APIENTRY *avpPFNGLDELETEPROGRAMPROC)(GLuint);
typedef void (APIENTRY *avpPFNGLDELETESHADERPROC)(GLuint);
typedef void (APIENTRY *avpPFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint);
typedef void (APIENTRY *avpPFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint);
typedef void (APIENTRY *avpPFNGLGENBUFFERSPROC)(GLsizei, GLuint*);
typedef int (APIENTRY *avpPFNGLGETATTRIBLOCATIONPROC)(GLuint, const GLchar*);
typedef void (APIENTRY *avpPFNGLGETPROGRAMINFOLOGPROC)(GLuint, GLsizei, GLsizei*, GLchar*);
typedef void (APIENTRY *avpPFNGLGETPROGRAMIVPROC)(GLuint, GLenum, GLint*);
typedef void (APIENTRY *avpPFNGLGETSHADERINFOLOGPROC)(GLuint, GLsizei, GLsizei*, GLchar*);
typedef void (APIENTRY *avpPFNGLGETSHADERIVPROC)(GLuint, GLenum, GLint*);
typedef int (APIENTRY *avpPFNGLGETUNIFORMLOCATIONPROC)(GLuint, const GLchar*);
typedef void (APIENTRY *avpPFNGLLINKPROGRAMPROC)(GLuint);
typedef void (APIENTRY *avpPFNGLSHADERSOURCEPROC)(GLuint, GLsizei, const GLchar* const*, const GLint*);
typedef void (APIENTRY *avpPFNGLVALIDATEPROGRAMPROC)(GLuint);
typedef void (APIENTRY *avpPFNGLVERTEXATTRIBPOINTERPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid*);
typedef void (APIENTRY *avpPFNGLUNIFORM1IPROC)(GLint, GLint);
typedef void (APIENTRY *avpPFNGLUNIFORMMATRIX4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat*);
typedef void (APIENTRY *avpPFNGLUSEPROGRAMPROC)(GLuint);

extern avpPFNGLATTACHSHADERPROC pglAttachShader;
extern avpPFNGLBINDATTRIBLOCATIONPROC pglBindAttribLocation;
extern avpPFNGLBINDBUFFERPROC pglBindBuffer;
extern avpPFNGLBUFFERDATAPROC pglBufferData;
extern avpPFNGLBUFFERSUBDATAPROC pglBufferSubData;
extern avpPFNGLCREATEPROGRAMPROC pglCreateProgram;
extern avpPFNGLCREATESHADERPROC pglCreateShader;
extern avpPFNGLCOMPILESHADERPROC pglCompileShader;
extern avpPFNGLDELETEBUFFERSPROC pglDeleteBuffers;
extern avpPFNGLDELETEPROGRAMPROC pglDeleteProgram;
extern avpPFNGLDELETESHADERPROC pglDeleteShader;
extern avpPFNGLDISABLEVERTEXATTRIBARRAYPROC pglDisableVertexAttribArray;
extern avpPFNGLENABLEVERTEXATTRIBARRAYPROC pglEnableVertexAttribArray;
extern avpPFNGLGENBUFFERSPROC pglGenBuffers;
extern avpPFNGLGETATTRIBLOCATIONPROC pglGetAttribLocation;
extern avpPFNGLGETPROGRAMINFOLOGPROC pglGetProgramInfoLog;
extern avpPFNGLGETPROGRAMIVPROC pglGetProgramiv;
extern avpPFNGLGETSHADERINFOLOGPROC pglGetShaderInfoLog;
extern avpPFNGLGETSHADERIVPROC pglGetShaderiv;
extern avpPFNGLGETUNIFORMLOCATIONPROC pglGetUniformLocation;
extern avpPFNGLLINKPROGRAMPROC pglLinkProgram;
extern avpPFNGLSHADERSOURCEPROC pglShaderSource;
extern avpPFNGLVALIDATEPROGRAMPROC pglValidateProgram;
extern avpPFNGLVERTEXATTRIBPOINTERPROC pglVertexAttribPointer;
extern avpPFNGLUNIFORM1IPROC pglUniform1i;
extern avpPFNGLUNIFORMMATRIX4FVPROC pglUniformMatrix4fv;
extern avpPFNGLUSEPROGRAMPROC pglUseProgram;

// GL_EXT_framebuffer_object / GL_ARB_framebuffer_object / OpenGL ES 2.0
typedef void (APIENTRY *avpPFNGLBINDFRAMEBUFFERPROC)(GLenum, GLuint);
typedef void (APIENTRY *avpPFNGLBINDRENDERBUFFERPROC)(GLenum, GLuint);
typedef GLenum (APIENTRY *avpPFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum);
typedef void (APIENTRY *avpPFNGLDELETEFRAMEBUFFERSPROC)(GLsizei, const GLuint*);
typedef void (APIENTRY *avpPFNGLDELETERENDERBUFFERSPROC)(GLsizei, const GLuint*);
typedef void (APIENTRY *avpPFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum, GLenum, GLenum, GLuint);
typedef void (APIENTRY *avpPFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum, GLenum, GLenum, GLuint, GLint);
typedef void (APIENTRY *avpPFNGLGENERATEMIPMAPPROC)(GLenum);
typedef void (APIENTRY *avpPFNGLGENFRAMEBUFFERSPROC)(GLsizei, GLuint*);
typedef void (APIENTRY *avpPFNGLGENRENDERBUFFERSPROC)(GLsizei, GLuint*);
typedef void (APIENTRY *avpPFNGLRENDERBUFFERSTORAGEPROC)(GLenum, GLenum, GLsizei, GLsizei);

extern avpPFNGLBINDFRAMEBUFFERPROC pglBindFramebuffer;
extern avpPFNGLBINDRENDERBUFFERPROC pglBindRenderbuffer;
extern avpPFNGLCHECKFRAMEBUFFERSTATUSPROC pglCheckFramebufferStatus;
extern avpPFNGLDELETEFRAMEBUFFERSPROC pglDeleteFramebuffers;
extern avpPFNGLDELETERENDERBUFFERSPROC pglDeleteRenderbuffers;
extern avpPFNGLFRAMEBUFFERRENDERBUFFERPROC pglFramebufferRenderbuffer;
extern avpPFNGLFRAMEBUFFERTEXTURE2DPROC pglFramebufferTexture2D;
extern avpPFNGLGENERATEMIPMAPPROC pglGenerateMipmap;
extern avpPFNGLGENFRAMEBUFFERSPROC pglGenFramebuffers;
extern avpPFNGLGENRENDERBUFFERSPROC pglGenRenderbuffers;
extern avpPFNGLRENDERBUFFERSTORAGEPROC pglRenderbufferStorage;


extern int ogl_have_multisample_filter_hint;
extern int ogl_have_texture_filter_anisotropic;
extern int ogl_have_framebuffer_object;

extern int ogl_use_multisample_filter_hint;
extern int ogl_use_texture_filter_anisotropic;
extern int ogl_use_framebuffer_object;

extern void load_ogl_functions(int mode);

extern int check_for_errors_(const char *file, int line);
#define check_for_errors() check_for_errors_(__FILE__, __LINE__)

#endif
