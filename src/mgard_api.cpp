// Copyright 2017, Brown University, Providence, RI.
//
//                         All Rights Reserved
//
// Permission to use, copy, modify, and distribute this software and
// its documentation for any purpose other than its incorporation into a
// commercial product or service is hereby granted without fee, provided
// that the above copyright notice appear in all copies and that both
// that copyright notice and this permission notice appear in supporting
// documentation, and that the name of Brown University not be used in
// advertising or publicity pertaining to distribution of the software
// without specific, written prior permission.
//
// BROWN UNIVERSITY DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
// INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ANY
// PARTICULAR PURPOSE.  IN NO EVENT SHALL BROWN UNIVERSITY BE LIABLE FOR
// ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
//
// MGARD: MultiGrid Adaptive Reduction of Data
// Authors: Mark Ainsworth, Ozan Tugluk, Ben Whitney
// Corresponding Author: Ozan Tugluk
//
// version: 0.0.0.2
//
// This file is part of MGARD.
//
// MGARD is distributed under the OSI-approved Apache License, Version 2.0.
// See accompanying file Copyright.txt for details.
//

#include "mgard.h"
#include "mgard_api.h"


 unsigned char *mgard_compress(int itype_flag,  double  *v, int &out_size, int nrow, int ncol, int nfib, double tol_in)

 //Perform compression preserving the tolerance in the L-infty norm
{ 
  if(itype_flag == 0)
    {
      // float *v   = static_cast<float*>(data);
      // float *tol = static_cast<float*>(tol_in);
      double tol = tol_in;
      assert (tol >= 1e-8);
      
      unsigned char* mgard_compressed_ptr = nullptr;

      //mgard_compressed_ptr = mgard::refactor_qz_float(nrow, ncol, v, out_size, *tol);

      return mgard_compressed_ptr;
    }
  else if(itype_flag == 1)
    {
      // double *v   = static_cast<double*>(data);
      // double *tol = static_cast<double*>(tol_in);
      double tol = tol_in;
      assert (tol >= 1e-8);
      unsigned char* mgard_compressed_ptr = nullptr;
      if(nrow > 1 && ncol > 1 && nfib > 1)
        {
          assert (nrow > 3);
          assert (ncol > 3);
          assert (nfib > 3);
          
	  mgard_compressed_ptr = mgard::refactor_qz(nrow, ncol, nfib, v, out_size, tol);
          return mgard_compressed_ptr;
                
        }
      else if (nrow > 1 && ncol > 1)
        {
          assert (nrow > 3);
          assert (ncol > 3);
          mgard_compressed_ptr = mgard::refactor_qz_2D(nrow, ncol, v, out_size, tol);
          return mgard_compressed_ptr;
        }
      else if (nrow > 1 )
        {
          assert (nrow > 3);
          //mgard_compressed_ptr = mgard::refactor_qz_1D(nrow, v, out_size, *tol);
        }

      
    }
  else
    {
      std::cerr <<"MGARD: Unknown data type, assuming 32-bit floats...\n";
      // const float *v = static_cast<const float*>(data);
      // float *tol = static_cast<float*>(tol_in);

      double tol = tol_in;
      assert (tol >= 1e-8);
      
      unsigned char* mgard_compressed_ptr = nullptr;

      //mgard_compressed_ptr = mgard::refactor_qz_float(nrow, ncol, v, out_size, *tol);

      return mgard_compressed_ptr;
    }
  
}




unsigned char *mgard_compress(int itype_flag,  double  *v, int &out_size, int nrow, int ncol, int nfib, double tol_in, double s )
{
  //Perform compression preserving the tolerance in s norm by defaulting to the L-2 norm
  if(itype_flag == 0)
    {
      // float *v   = static_cast<float*>(data);
      // float *tol = static_cast<float*>(tol_in);

      double tol = tol_in;
      assert (tol >= 1e-8);
      
      unsigned char* mgard_compressed_ptr = nullptr;

      //mgard_compressed_ptr = mgard::refactor_qz_float(nrow, ncol, v, out_size, *tol);

      return mgard_compressed_ptr;
    }
  else if(itype_flag == 1)
    {
      // double *v   = static_cast<double*>(data);
      // double *tol = static_cast<double*>(tol_in);
      double tol = tol_in;
      assert (tol >= 1e-8);
      //      std::cout << "Input "  << v[100] << std::endl;
      unsigned char* mgard_compressed_ptr = nullptr;
      if(nrow > 1 && ncol > 1 && nfib > 1)
        {
          assert (nrow > 3);
          assert (ncol > 3);
          assert (nfib > 3);
          
          mgard_compressed_ptr = mgard::refactor_qz(nrow, ncol, nfib, v, out_size, tol, s);
          return mgard_compressed_ptr;
                
        }
      else if (nrow > 1 && ncol > 1)
        {
          assert (nrow > 3);
          assert (ncol > 3);
          mgard_compressed_ptr = mgard::refactor_qz_2D(nrow, ncol, v, out_size, tol);
          //          mgard_compressed_ptr = mgard::refactor_qz_2D(nrow, ncol, v, out_size, *tol);
          return mgard_compressed_ptr;
        }
      else if (nrow > 1 )
        {
          assert (nrow > 3);
          //mgard_compressed_ptr = mgard::refactor_qz_1D(nrow, v, out_size, *tol);
        }

      
    }
  else
    {
      std::cerr <<"MGARD: Unknown data type, assuming 32-bit floats...\n";
      
      unsigned char* mgard_compressed_ptr = nullptr;

      //mgard_compressed_ptr = mgard::refactor_qz_float(nrow, ncol, v, out_size, *tol);

      return mgard_compressed_ptr;
    }
  
}



unsigned char *mgard_compress(int itype_flag,  double  *v, int &out_size, int nrow, int ncol, int nfib, double tol_in, double (*qoi) (int, int, int, std::vector<double>), double s)
{
  //Perform compression preserving the tolerance in s norm by defaulting to the L-2 norm
  if(itype_flag == 0)
    {
 
      double tol = tol_in;
      assert (tol >= 1e-8);
      
      unsigned char* mgard_compressed_ptr = nullptr;

      //mgard_compressed_ptr = mgard::refactor_qz_float(nrow, ncol, v, out_size, *tol);

      return mgard_compressed_ptr;
    }
  else if(itype_flag == 1)
    {
 
      double tol = tol_in;
      assert (tol >= 1e-8);
      unsigned char* mgard_compressed_ptr = nullptr;
      if(nrow > 1 && ncol > 1 && nfib > 1)
        {
          assert (nrow > 3);
          assert (ncol > 3);
          assert (nfib > 3);
	  
          mgard_compressed_ptr = mgard::refactor_qz(nrow, ncol, nfib, v, out_size, tol, qoi, s);
          return mgard_compressed_ptr;
                
        }
      else if (nrow > 1 && ncol > 1)
        {
          assert (nrow > 3);
          assert (ncol > 3);
          mgard_compressed_ptr = mgard::refactor_qz_2D(nrow, ncol, v, out_size, tol);
          //          mgard_compressed_ptr = mgard::refactor_qz_2D(nrow, ncol, v, out_size, *tol);
          return mgard_compressed_ptr;
        }
      else if (nrow > 1 )
        {
          assert (nrow > 3);
          //mgard_compressed_ptr = mgard::refactor_qz_1D(nrow, v, out_size, *tol);
        }

      
    }
  else
    {
      std::cerr <<"MGARD: Unknown data type, assuming 32-bit floats...\n";
      // const float *v = static_cast<const float*>(data);
      // float *tol = static_cast<float*>(tol_in);
      // assert (*tol >= 1e-8);
      
      unsigned char* mgard_compressed_ptr = nullptr;

      //mgard_compressed_ptr = mgard::refactor_qz_float(nrow, ncol, v, out_size, *tol);

      return mgard_compressed_ptr;
    }
  
}

double *mgard_decompress(int itype_flag,  unsigned char *data, int data_len, int nrow, int ncol, int nfib)
{
  assert (ncol > 3);
  assert (nrow >= 1);

  if(itype_flag == 0)
    {
      
      float* mgard_decompressed_ptr;

      //      mgard_decompressed_ptr = mgard::recompose_udq_float(nrow, ncol, v, out_size, *tol);

      //      return mgard_decompressed_ptr;
    }
  else if(itype_flag == 1)
    {
      
      double* mgard_decompressed_ptr = nullptr;
      
      //      mgard_decompressed_ptr = static_cast<double*> (mgard::recompose_udq(nrow, ncol, data, data_len));



      if(nrow > 1 && ncol > 1 && nfib > 1)
        {
          assert (nrow > 3);
          assert (ncol > 3);
          assert (nfib > 3);
	  
          mgard_decompressed_ptr = mgard::recompose_udq(nrow, ncol, nfib, data, data_len);
          return mgard_decompressed_ptr;      
        }
      else if (nrow > 1 && ncol > 1)
        {
          assert (nrow > 3);
          assert (ncol > 3);
          mgard_decompressed_ptr = mgard::recompose_udq_2D(nrow, ncol, data, data_len);
          //          mgard_decompressed_ptr = mgard::recompose_udq_2D(nrow, ncol, data, data_len);
          return mgard_decompressed_ptr;
        }
      else if (nrow > 1 )
        {
          assert (nrow > 3);
          //mgard_decompressed_ptr = mgard::recompose_udq_1D(nrow,  data, data_len);
        }
      

    }
  else
    {
      std::cerr <<"MGARD: Unknown data type, assuming 32-bit floats...\n";

      float* mgard_decompressed_ptr = nullptr;

      //mgard_decompressed_ptr = mgard::recompose_udq_float(nrow, ncol, v, out_size, *tol);

    }
  
}


double  *mgard_decompress(int itype_flag,  unsigned char *data, int data_len, int nrow, int ncol, int nfib, double s)
{
  assert (ncol > 3);
  assert (nrow >= 1);

  if(itype_flag == 0)
    {
      
      float* mgard_decompressed_ptr;

      //      mgard_decompressed_ptr = mgard::recompose_udq_float(nrow, ncol, v, out_size, *tol);

      //      return mgard_decompressed_ptr;
    }
  else if(itype_flag == 1)
    {
      
      double* mgard_decompressed_ptr = nullptr;

      //      mgard_decompressed_ptr = static_cast<double*> (mgard::recompose_udq(nrow, ncol, data, data_len));



      if(nrow > 1 && ncol > 1 && nfib > 1)
        {
          assert (nrow > 3);
          assert (ncol > 3);
          assert (nfib > 3);

          mgard_decompressed_ptr = mgard::recompose_udq(nrow, ncol, nfib, data, data_len, s);
          return mgard_decompressed_ptr;      
        }
      else if (nrow > 1 && ncol > 1)
        {
          assert (nrow > 3);
          assert (ncol > 3);
          mgard_decompressed_ptr = mgard::recompose_udq_2D(nrow, ncol, data, data_len);
          //          mgard_decompressed_ptr = mgard::recompose_udq_2D(nrow, ncol, data, data_len);
          return mgard_decompressed_ptr;
        }
      else if (nrow > 1 )
        {
          assert (nrow > 3);
          //mgard_decompressed_ptr = mgard::recompose_udq_1D(nrow,  data, data_len);
        }
      

    }
  else
    {
      std::cerr <<"MGARD: Unknown data type, assuming 32-bit floats...\n";

      float* mgard_decompressed_ptr = nullptr;

      //mgard_decompressed_ptr = mgard::recompose_udq_float(nrow, ncol, v, out_size, *tol);

    }
  
}





