/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkSobelEdgeDetectionImageFilter.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkSobelEdgeDetectionImageFilter_h
#define __itkSobelEdgeDetectionImageFilter_h

#include "itkImageToImageFilter.h"
#include "itkImage.h"

namespace itk
{
/**
 * \class SobelEdgeDetectionImageFilter
 * \brief Implements the Sobel Edge Detection.The Sobel operator performs a 2D/ND spatial
 *  gradient  measurement on an image and so emphasizes regions of high spatial gradient 
 *  that correspond to edges. Typically it is used to find the approximate absolute gradient 
 *   magnitude at each point in an input greyscale image
 *  
 *  In this filter, the Sobel operator is first applied to each direction just
 *  like calculating the derivative image filters. then the the gradient magnitude is 
 *  calculated, which indicates where the edges are.

 * \sa ImageToImageFilter
 * \sa SobelOperator
 * \sa Neighborhood
 * \sa NeighborhoodOperator
 * \sa NeighborhoodIterator
 * 
 * \ingroup ImageFeatureExtraction 
 *
 */

template <class TInputImage, class TOutputImage>
class ITK_EXPORT SobelEdgeDetectionImageFilter : 
           public ImageToImageFilter< TInputImage, TOutputImage > 
{
public:
  /**
   * Standard "Self" & Superclass typedef.
   */
  typedef SobelEdgeDetectionImageFilter Self;
  typedef ImageToImageFilter< TInputImage, TOutputImage > Superclass;

  /**
   * Extract some information from the image types.  Dimensionality
   * of the two images is assumed to be the same.
   */
  typedef typename TOutputImage::PixelType OutputPixelType;
  typedef typename TOutputImage::InternalPixelType OutputInternalPixelType;
  typedef typename TInputImage::PixelType InputPixelType;
  typedef typename TInputImage::InternalPixelType InputInternalPixelType;
  itkStaticConstMacro(ImageDimension, unsigned int,
                      TOutputImage::ImageDimension );
  
  /**
   * Image typedef support
   */
  typedef TInputImage  InputImageType;
  typedef TOutputImage OutputImageType;
  typedef typename InputImageType::Pointer InputImagePointer;

  /** 
   * Smart pointer typedef support 
   */
  typedef SmartPointer<Self> Pointer;
  typedef SmartPointer<const Self>  ConstPointer;
  
  /**
   * Run-time type information (and related methods)
   */
  itkTypeMacro(SobelEdgeDetectionImageFilter, ImageToImageFilter);
  
  /**
   * Method for creation through the object factory.
   */
  itkNewMacro(Self);

  /**
   * SobelEdgeDetectionImageFilter needs a larger input requested region than
   * the output requested region (larger in the direction of the
   * derivative).  As such, SobelEdgeDetectionImageFilter needs to provide an
   * implementation for GenerateInputRequestedRegion() in order to
   * inform the pipeline execution model.
   *
   * \sa ImageToImageFilter::GenerateInputRequestedRegion()
   */
  virtual void GenerateInputRequestedRegion() throw(InvalidRequestedRegionError);

protected:
  SobelEdgeDetectionImageFilter() {}
  virtual ~SobelEdgeDetectionImageFilter() {}
  SobelEdgeDetectionImageFilter(const Self&) {}
  //void operator=(const Self&) {}

  /**
   * Standard pipeline method. While this class does not implement a
   * ThreadedGenerateData(), its GenerateData() delegates all
   * calculations to an NeighborhoodOperatorImageFilter.  Since the
   * NeighborhoodOperatorImageFilter is multithreaded, this filter is
   * multithreaded by default.
   */
  void GenerateData();
  void PrintSelf(std::ostream& os, Indent indent) const
    { Superclass::PrintSelf(os,indent); }

  
private:

};
  
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkSobelEdgeDetectionImageFilter.txx"
#endif

#endif
