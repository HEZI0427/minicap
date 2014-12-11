#ifndef MINICAP_UTIL_CAPSTER_HPP
#define MINICAP_UTIL_CAPSTER_HPP

#include <memory>

#include <turbojpeg.h>
#include <minicap.hpp>

class capster {
public:
  class display_info {
  public:
    uint32_t width;
    uint32_t height;
    float xdpi;
    float ydpi;
    float size;
    float density;
  };

  static display_info
  get_display_info(uint32_t display_id);

  capster(uint32_t display_id);

  int
  initial_update();

  int
  update();

  int
  convert();

  int
  get_size();

  unsigned char*
  get_data();

  void
  set_desired_size(unsigned int width, unsigned int height);

private:
  int
  reserve_data();

  tjhandle m_tjhandle;
  std::unique_ptr<minicap> m_minicap;
  int m_subsampling;
  unsigned int m_quality;
  unsigned int m_format;
  unsigned int m_max_width;
  unsigned int m_max_height;
  unsigned int m_max_quality;
  unsigned char* m_data;
  unsigned long m_data_size;
  unsigned int m_desired_width;
  unsigned int m_desired_height;
};

#endif