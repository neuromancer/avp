#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SDL.h"

#include "oglfunc.h"

// Base OpenGL / OpenGL ES
avpPFNGLACTIVETEXTUREPROC pglActiveTexture;
avpPFNGLBINDTEXTUREPROC		pglBindTexture;
avpPFNGLBLENDFUNCPROC		pglBlendFunc;
avpPFNGLCLEARPROC			pglClear;
avpPFNGLCLEARCOLORPROC		pglClearColor;
avpPFNGLCULLFACEPROC		pglCullFace;
avpPFNGLDELETETEXTURESPROC		pglDeleteTextures;
avpPFNGLDEPTHFUNCPROC		pglDepthFunc;
avpPFNGLDEPTHMASKPROC		pglDepthMask;
avpPFNGLDEPTHRANGEPROC		pglDepthRange;
avpPFNGLDISABLEPROC		pglDisable;
avpPFNGLDRAWELEMENTSPROC		pglDrawElements;
avpPFNGLENABLEPROC			pglEnable;
avpPFNGLFRONTFACEPROC		pglFrontFace;
avpPFNGLGENTEXTURESPROC		pglGenTextures;
avpPFNGLGETERRORPROC		pglGetError;
avpPFNGLGETFLOATVPROC		pglGetFloatv;
avpPFNGLGETINTEGERVPROC		pglGetIntegerv;
avpPFNGLGETSTRINGPROC		pglGetString;
avpPFNGLGETTEXPARAMETERFVPROC	pglGetTexParameterfv;
avpPFNGLHINTPROC			pglHint;
avpPFNGLPIXELSTOREIPROC		pglPixelStorei;
avpPFNGLPOLYGONOFFSETPROC		pglPolygonOffset;
avpPFNGLREADPIXELSPROC		pglReadPixels;
avpPFNGLTEXIMAGE2DPROC		pglTexImage2D;
avpPFNGLTEXPARAMETERFPROC		pglTexParameterf;
avpPFNGLTEXPARAMETERIPROC		pglTexParameteri;
avpPFNGLTEXSUBIMAGE2DPROC		pglTexSubImage2D;
avpPFNGLVIEWPORTPROC		pglViewport;

// OpenGL 2.1 / OpenGL ES 2.0
avpPFNGLATTACHSHADERPROC pglAttachShader;
avpPFNGLBINDATTRIBLOCATIONPROC pglBindAttribLocation;
avpPFNGLBINDBUFFERPROC pglBindBuffer;
avpPFNGLBUFFERDATAPROC pglBufferData;
avpPFNGLBUFFERSUBDATAPROC pglBufferSubData;
avpPFNGLCREATEPROGRAMPROC pglCreateProgram;
avpPFNGLCREATESHADERPROC pglCreateShader;
avpPFNGLCOMPILESHADERPROC pglCompileShader;
avpPFNGLDELETEBUFFERSPROC pglDeleteBuffers;
avpPFNGLDELETEPROGRAMPROC pglDeleteProgram;
avpPFNGLDELETESHADERPROC pglDeleteShader;
avpPFNGLDISABLEVERTEXATTRIBARRAYPROC pglDisableVertexAttribArray;
avpPFNGLENABLEVERTEXATTRIBARRAYPROC pglEnableVertexAttribArray;
avpPFNGLGENBUFFERSPROC pglGenBuffers;
avpPFNGLGETATTRIBLOCATIONPROC pglGetAttribLocation;
avpPFNGLGETPROGRAMINFOLOGPROC pglGetProgramInfoLog;
avpPFNGLGETPROGRAMIVPROC pglGetProgramiv;
avpPFNGLGETSHADERINFOLOGPROC pglGetShaderInfoLog;
avpPFNGLGETSHADERIVPROC pglGetShaderiv;
avpPFNGLGETUNIFORMLOCATIONPROC pglGetUniformLocation;
avpPFNGLLINKPROGRAMPROC pglLinkProgram;
avpPFNGLSHADERSOURCEPROC pglShaderSource;
avpPFNGLVALIDATEPROGRAMPROC pglValidateProgram;
avpPFNGLVERTEXATTRIBPOINTERPROC pglVertexAttribPointer;
avpPFNGLUNIFORM1IPROC pglUniform1i;
avpPFNGLUNIFORMMATRIX4FVPROC pglUniformMatrix4fv;
avpPFNGLUSEPROGRAMPROC pglUseProgram;

// GL_EXT_framebuffer_object / GL_ARB_framebuffer_object / OpenGL ES 2.0
avpPFNGLBINDFRAMEBUFFERPROC pglBindFramebuffer;
avpPFNGLBINDRENDERBUFFERPROC pglBindRenderbuffer;
avpPFNGLCHECKFRAMEBUFFERSTATUSPROC pglCheckFramebufferStatus;
avpPFNGLDELETEFRAMEBUFFERSPROC pglDeleteFramebuffers;
avpPFNGLDELETERENDERBUFFERSPROC pglDeleteRenderbuffers;
avpPFNGLFRAMEBUFFERRENDERBUFFERPROC pglFramebufferRenderbuffer;
avpPFNGLFRAMEBUFFERTEXTURE2DPROC pglFramebufferTexture2D;
avpPFNGLGENERATEMIPMAPPROC pglGenerateMipmap;
avpPFNGLGENFRAMEBUFFERSPROC pglGenFramebuffers;
avpPFNGLGENRENDERBUFFERSPROC pglGenRenderbuffers;
avpPFNGLRENDERBUFFERSTORAGEPROC pglRenderbufferStorage;

int ogl_have_multisample_filter_hint;
int ogl_have_texture_filter_anisotropic;
int ogl_have_framebuffer_object;

int ogl_use_multisample_filter_hint;
int ogl_use_texture_filter_anisotropic;
int ogl_use_framebuffer_object;

static void dummyfunc()
{
}

#define LoadOGLProc_(type, func, name) {                    \
	if (!mode) p##func = (type) dummyfunc; else			\
	p##func = (type) SDL_GL_GetProcAddress(#name);			\
	if (p##func == NULL) {						\
		if (!ogl_missing_func) ogl_missing_func = #func;	\
	}								\
}

#define LoadOGLProc(type, func)						\
	LoadOGLProc_(type, func, func)

#define LoadOGLProc2(type, func1, func2)					\
	LoadOGLProc_(type, func1, func1); \
	if (p##func1 == NULL) { \
		ogl_missing_func = NULL; \
		LoadOGLProc_(type, func1, func2); \
	}

#define LoadOGLExtProc(e, type, func)						\
	if ((e)) { \
		LoadOGLProc(type, func); \
	} else { \
		p##func = NULL; \
	}

#define LoadOGLExtProc2(e, type, func1, func2)					\
	if ((e)) { \
		LoadOGLProc2(type, func1, func2); \
	} else { \
		p##func = NULL; \
	}

static int check_token(const char *string, const char *token)
{
	const char *s = string;
	int len = strlen(token);
	
	while ((s = strstr(s, token)) != NULL) {
		const char *next = s + len;
		
		if ((s == string || *(s-1) == ' ') &&
			(*next == 0 || *next == ' ')) {
			
			return 1;
		}
		
		s = next;
	}
	
	return 0;
}

void load_ogl_functions(int mode)
{
	const char* ogl_missing_func;
	const char* ext;

	int base_framebuffer_object;
	int ext_framebuffer_object;
	int arb_framebuffer_object;

	ogl_missing_func = NULL;
	
	// Base OpenGL / OpenGL ES
	LoadOGLProc(avpPFNGLACTIVETEXTUREPROC, glActiveTexture);
	LoadOGLProc(avpPFNGLBINDTEXTUREPROC, glBindTexture);
	LoadOGLProc(avpPFNGLBLENDFUNCPROC, glBlendFunc);
	LoadOGLProc(avpPFNGLCLEARPROC, glClear);
	LoadOGLProc(avpPFNGLCLEARCOLORPROC, glClearColor);
	LoadOGLProc(avpPFNGLCULLFACEPROC, glCullFace);
	LoadOGLProc(avpPFNGLDELETETEXTURESPROC, glDeleteTextures);
	LoadOGLProc(avpPFNGLDEPTHFUNCPROC, glDepthFunc);
	LoadOGLProc(avpPFNGLDEPTHMASKPROC, glDepthMask);
	LoadOGLProc2(avpPFNGLDEPTHRANGEPROC, glDepthRange, glDepthRangef);
	LoadOGLProc(avpPFNGLDISABLEPROC, glDisable);
	LoadOGLProc(avpPFNGLDRAWELEMENTSPROC, glDrawElements);
	LoadOGLProc(avpPFNGLENABLEPROC, glEnable);
	LoadOGLProc(avpPFNGLFRONTFACEPROC, glFrontFace);
	LoadOGLProc(avpPFNGLGENTEXTURESPROC, glGenTextures);
	LoadOGLProc(avpPFNGLGETERRORPROC, glGetError);
	LoadOGLProc(avpPFNGLGETFLOATVPROC, glGetFloatv);
	LoadOGLProc(avpPFNGLGETINTEGERVPROC, glGetIntegerv);
	LoadOGLProc(avpPFNGLGETSTRINGPROC, glGetString);
	LoadOGLProc(avpPFNGLGETTEXPARAMETERFVPROC, glGetTexParameterfv);
	LoadOGLProc(avpPFNGLHINTPROC, glHint);
	LoadOGLProc(avpPFNGLPIXELSTOREIPROC, glPixelStorei);
	LoadOGLProc(avpPFNGLPOLYGONOFFSETPROC, glPolygonOffset);
	LoadOGLProc(avpPFNGLREADPIXELSPROC, glReadPixels);
	LoadOGLProc(avpPFNGLTEXIMAGE2DPROC, glTexImage2D);
	LoadOGLProc(avpPFNGLTEXPARAMETERFPROC, glTexParameterf);
	LoadOGLProc(avpPFNGLTEXPARAMETERIPROC, glTexParameteri);
	LoadOGLProc(avpPFNGLTEXSUBIMAGE2DPROC, glTexSubImage2D);
	LoadOGLProc(avpPFNGLVIEWPORTPROC, glViewport);

	// OpenGL 2.1 / OpenGL ES 2.0
	LoadOGLProc(avpPFNGLATTACHSHADERPROC, glAttachShader);
	LoadOGLProc(avpPFNGLBINDATTRIBLOCATIONPROC, glBindAttribLocation);
	LoadOGLProc(avpPFNGLBINDBUFFERPROC, glBindBuffer);
	LoadOGLProc(avpPFNGLBUFFERDATAPROC, glBufferData);
	LoadOGLProc(avpPFNGLBUFFERSUBDATAPROC, glBufferSubData);
	LoadOGLProc(avpPFNGLCREATEPROGRAMPROC, glCreateProgram);
	LoadOGLProc(avpPFNGLCREATESHADERPROC, glCreateShader);
	LoadOGLProc(avpPFNGLCOMPILESHADERPROC, glCompileShader);
	LoadOGLProc(avpPFNGLDELETEBUFFERSPROC, glDeleteBuffers);
	LoadOGLProc(avpPFNGLDELETEPROGRAMPROC, glDeleteProgram);
	LoadOGLProc(avpPFNGLDELETESHADERPROC, glDeleteShader);
	LoadOGLProc(avpPFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray);
	LoadOGLProc(avpPFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray);
	LoadOGLProc(avpPFNGLGENBUFFERSPROC, glGenBuffers);
	LoadOGLProc(avpPFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation);
	LoadOGLProc(avpPFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog);
	LoadOGLProc(avpPFNGLGETPROGRAMIVPROC, glGetProgramiv);
	LoadOGLProc(avpPFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog);
	LoadOGLProc(avpPFNGLGETSHADERIVPROC, glGetShaderiv);
	LoadOGLProc(avpPFNGLGETUNIFORMLOCATIONPROC, glGetUniformLocation);
	LoadOGLProc(avpPFNGLLINKPROGRAMPROC, glLinkProgram);
	LoadOGLProc(avpPFNGLSHADERSOURCEPROC, glShaderSource);
	LoadOGLProc(avpPFNGLVALIDATEPROGRAMPROC, glValidateProgram);
	LoadOGLProc(avpPFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer);
	LoadOGLProc(avpPFNGLUNIFORM1IPROC, glUniform1i);
	LoadOGLProc(avpPFNGLUNIFORMMATRIX4FVPROC, glUniformMatrix4fv);
	LoadOGLProc(avpPFNGLUSEPROGRAMPROC, glUseProgram);

	if (!mode) {
		return;
	}
	
	if (ogl_missing_func) {
		fprintf(stderr, "Unable to load OpenGL Library: missing function %s\n", ogl_missing_func);
		exit(EXIT_FAILURE);
	}
	
#if !defined(NDEBUG)
	printf("GL_VENDOR: %s\n", pglGetString(GL_VENDOR));
	printf("GL_RENDERER: %s\n", pglGetString(GL_RENDERER));
	printf("GL_VERSION: %s\n", pglGetString(GL_VERSION));
	printf("GL_SHADING_LANGUAGE_VERSION: %s\n", pglGetString(GL_SHADING_LANGUAGE_VERSION));
	printf("GL_EXTENSIONS: %s\n", pglGetString(GL_EXTENSIONS));
#endif

	ext = (const char *) pglGetString(GL_EXTENSIONS);

	// GL_EXT_framebuffer_object / GL_ARB_framebuffer_object / OpenGL ES 2.0
	// figure out which version of framebuffer objects to use, if any
	ext_framebuffer_object = check_token(ext, "GL_EXT_framebuffer_object");
	arb_framebuffer_object = check_token(ext, "GL_ARB_framebuffer_object");

#if defined(USE_OPENGL_ES)
	// not quite right as ARB fbo includes functionality not present in ES2.
	base_framebuffer_object = 1;
#else
	base_framebuffer_object = arb_framebuffer_object;
#endif

	ogl_missing_func = NULL;
	LoadOGLExtProc(base_framebuffer_object, avpPFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer);
	LoadOGLExtProc(base_framebuffer_object, avpPFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer);
	LoadOGLExtProc(base_framebuffer_object, avpPFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus);
	LoadOGLExtProc(base_framebuffer_object, avpPFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffers);
	LoadOGLExtProc(base_framebuffer_object, avpPFNGLDELETERENDERBUFFERSPROC, glDeleteRenderbuffers);
	LoadOGLExtProc(base_framebuffer_object, avpPFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer);
	LoadOGLExtProc(base_framebuffer_object, avpPFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D);
	LoadOGLExtProc(base_framebuffer_object, avpPFNGLGENERATEMIPMAPPROC, glGenerateMipmap);
	LoadOGLExtProc(base_framebuffer_object, avpPFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers);
	LoadOGLExtProc(base_framebuffer_object, avpPFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers);
	LoadOGLExtProc(base_framebuffer_object, avpPFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage);
	if (base_framebuffer_object != 0 && ogl_missing_func == NULL) {
		ogl_have_framebuffer_object = 1;

#if !defined(NDEBUG)
		printf("ARB/ES2 framebuffer objects enabled.\n");
#endif
	}

	if (ext_framebuffer_object != 0 && ogl_have_framebuffer_object == 0) {
		// try the EXT suffixed functions
		ogl_missing_func = NULL;
		LoadOGLProc_(avpPFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer, glBindFramebufferEXT);
		LoadOGLProc_(avpPFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer, glBindRenderbufferEXT);
		LoadOGLProc_(avpPFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus, glCheckFramebufferStatusEXT);
		LoadOGLProc_(avpPFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffers, glDeleteFramebuffersEXT);
		LoadOGLProc_(avpPFNGLDELETERENDERBUFFERSPROC, glDeleteRenderbuffers, glDeleteRenderbuffersEXT);
		LoadOGLProc_(avpPFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer, glFramebufferRenderbufferEXT);
		LoadOGLProc_(avpPFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D, glFramebufferTexture2DEXT);
		LoadOGLProc_(avpPFNGLGENERATEMIPMAPPROC, glGenerateMipmap, glGenerateMipmapEXT);
		LoadOGLProc_(avpPFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers, glGenFramebuffersEXT);
		LoadOGLProc_(avpPFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers, glGenRenderbuffersEXT);
		LoadOGLProc_(avpPFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage, glRenderbufferStorageEXT);
		if (ogl_missing_func == NULL) {
			ogl_have_framebuffer_object = 1;

#if !defined(NDEBUG)
			printf("EXT framebuffer objects enabled.\n");
#endif
		}
	}

	// other extensions
	ogl_have_multisample_filter_hint = check_token(ext, "GL_NV_multisample_filter_hint");
	ogl_have_texture_filter_anisotropic = check_token(ext, "GL_EXT_texture_filter_anisotropic");

	ogl_use_multisample_filter_hint = ogl_have_multisample_filter_hint;
	ogl_use_texture_filter_anisotropic = ogl_have_texture_filter_anisotropic;
	ogl_use_framebuffer_object = ogl_have_framebuffer_object;
}

int check_for_errors_(const char *file, int line)
{
	GLenum error;
	int diderror = 0;
	
	while ((error = pglGetError()) != GL_NO_ERROR) {
		fprintf(stderr, "OPENGL ERROR: %04X (%s:%d)\n", error, file, line);
		
		diderror = 1;
	}
	
	return diderror;
}
