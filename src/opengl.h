#ifndef AVP_OPENGL_H
#define AVP_OPENGL_H

#include "kshape.h"


#define OPENGL_VERTEX_ATTRIB_INDEX 0
#define OPENGL_TEXCOORD_ATTRIB_INDEX 1
#define OPENGL_COLOR0_ATTRIB_INDEX 2
#define OPENGL_COLOR1_ATTRIB_INDEX 3

#define OPENGL_VERTEX_ATTRIB_BITINDEX (1 << OPENGL_VERTEX_ATTRIB_INDEX)
#define OPENGL_TEXCOORD_ATTRIB_BITINDEX (1 << OPENGL_TEXCOORD_ATTRIB_INDEX)
#define OPENGL_COLOR0_ATTRIB_BITINDEX (1 << OPENGL_COLOR0_ATTRIB_INDEX)
#define OPENGL_COLOR1_ATTRIB_BITINDEX (1 << OPENGL_COLOR1_ATTRIB_INDEX)

enum AVP_SHADER_PROGRAM {
	AVP_SHADER_PROGRAM_DEFAULT,
	AVP_SHADER_PROGRAM_NO_SECONDARY,
	AVP_SHADER_PROGRAM_NO_TEXTURE,
	AVP_SHADER_PROGRAM_NO_DISCARD,
	AVP_SHADER_PROGRAM_NO_SECONDARY_NO_DISCARD,
	AVP_SHADER_PROGRAM_NO_COLOR_NO_DISCARD,
	AVP_SHADER_PROGRAM_MAX
};

void SelectProgram(enum AVP_SHADER_PROGRAM program);
void DrawFullscreenTexture(int texureObject);

void InitOpenGL(int firsttime);
void ThisFramesRenderingHasBegun();
void ThisFramesRenderingHasFinished();
void D3D_SkyPolygon_Output(POLYHEADER *inputPolyPtr, RENDERVERTEX *renderVerticesPtr);
void D3D_DrawBackdrop();
void D3D_FadeDownScreen(int brightness, int colour);
void RenderString(char *stringPtr, int x, int y, int colour);
void RenderStringCentred(char *stringPtr, int centreX, int y, int colour);
void RenderStringVertically(char *stringPtr, int centreX, int bottomY, int colour);
void D3D_DecalSystem_Setup();
void D3D_DecalSystem_End();
void SecondFlushD3DZBuffer();
void D3D_PlayerDamagedOverlay(int intensity);
void D3D_PredatorScreenInversionOverlay();
void D3D_ScreenInversionOverlay();
void D3D_DrawColourBar(int yTop, int yBottom, int rScale, int gScale, int bScale);

#endif
