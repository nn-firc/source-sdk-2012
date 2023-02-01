#ifndef MAT_STUB_H
#define MAT_STUB_H
#include "materialsystem/itexture.h"

// ---------------------------------------------------------------------------------------- //
// ITexture dummy implementation.
// ---------------------------------------------------------------------------------------- //

class CDummyTexture : public ITexture
{
public:
	// Various texture polling methods
	virtual const char *GetName( void ) const { return "DummyTexture"; }
	virtual int GetMappingWidth() const { return 512; }
	virtual int GetMappingHeight() const { return 512; }
	virtual int GetActualWidth() const { return 512; }
	virtual int GetActualHeight() const { return 512; }
	virtual int GetNumAnimationFrames() const { return 0; }
	virtual bool IsTranslucent() const { return false; }
	virtual bool IsMipmapped() const { return false; }

	virtual void GetLowResColorSample( float s, float t, float *color ) const {}

	// Gets texture resource data of the specified type.
	// Params:
	//		eDataType		type of resource to retrieve.
	//		pnumBytes		on return is the number of bytes available in the read-only data buffer or is undefined
	// Returns:
	//		pointer to the resource data, or NULL
	virtual void *GetResourceData( uint32 eDataType, size_t *pNumBytes ) const
	{
		return NULL;
	}


	// Methods associated with reference count
	virtual void IncrementReferenceCount( void ) {}
	virtual void DecrementReferenceCount( void ) {}

	// Used to modify the texture bits (procedural textures only)
	virtual void SetTextureRegenerator( ITextureRegenerator *pTextureRegen, bool releaseExisting = true ) {}

	// Reconstruct the texture bits in HW memory

	// If rect is not specified, reconstruct all bits, otherwise just reconstruct a subrect.
	virtual void Download( Rect_t *pRect = 0, int nAdditionalCreationFlags = 0 ) {}

	// Fast download without intermediate vtf texture copy
	virtual void Download( int nXOffset, int nYOffset, unsigned char *pData, int nWidth, int nHeight, ImageFormat srcFormat ) {}

	// Uses for stats. . .get the approximate size of the texture in it's current format.
	virtual int GetApproximateVidMemBytes( void ) const { return 64; }

	virtual bool IsError() const { return false; }

	virtual ITexture *GetEmbeddedTexture( int nIndex ) { return NULL; }

	// For volume textures
	virtual bool IsVolumeTexture() const { return false; }
	virtual int GetMappingDepth() const { return 1; }
	virtual int GetActualDepth() const { return 1; }

	virtual ImageFormat GetImageFormat() const { return IMAGE_FORMAT_RGBA8888; }

	// Various information about the texture
	virtual bool IsRenderTarget() const { return false; }
	virtual bool IsCubeMap() const { return false; }
	virtual bool IsNormalMap() const { return false; }
	virtual bool IsProcedural() const { return false; }
	virtual void DeleteIfUnreferenced() {}
	virtual bool IsDefaultPool() const { return false; }

	virtual void SwapContents( ITexture *pOther ) {}

	virtual unsigned int GetFlags( void ) const { return 0; }
	virtual void ForceLODOverride( int iNumLodsOverrideUpOrDown ) { NULL; }
	virtual void ForceExcludeOverride( int iExcludeOverride ) { NULL; }

	virtual void AddDownsizedSubTarget( const char *szName, int iDownsizePow2, MaterialRenderTargetDepth_t depth ) { NULL; }
	virtual void SetActiveSubTarget( const char *szName ) { NULL; }

#if defined( _X360 )
	virtual bool ClearTexture( int r, int g, int b, int a ) { return true; }
	virtual bool CreateRenderTargetSurface( int width, int height, ImageFormat format, bool bSameAsTexture, RTMultiSampleCount360_t multiSampleCount = RT_MULTISAMPLE_NONE ) { return true; }
#endif

	virtual int GetReferenceCount() const { return 0; }

	virtual bool IsTempExcluded() const { return false; }
	virtual bool CanBeTempExcluded() const { return false; }

	virtual bool FinishAsyncDownload( AsyncTextureContext_t *pContext, void *pData, int nNumReadBytes, bool bAbort, float flMaxTimeMs ) { return true; }

	virtual bool IsForceExcluded() const { return false; }
	virtual bool ClearForceExclusion() { return false; }
};

extern CDummyTexture g_DummyTexture;

#endif // MAT_STUB_H
