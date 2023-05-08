/**
 * @file LogicZone_zenfs.h
 * @author TC(tomcaottt@gmail.com)
*/

#pragma once

// #if !defined(ROCKSDB_LITE) && defined(OS_LINUX)

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "rocksdb/io_status.h"
#include "liblogiczone.h"

namespace ROCKSDB_NAMESPACE {

class LogicZoneBackend : public ZonedBlockDeviceBackend {
 private:
  std::string filename_;
  int read_f_;
  int read_direct_f_;
  int write_f_;

 public:
  explicit LogicZoneBackend(std::string bdevname);
  ~LogicZoneBackend() {
    zbd_close(read_f_);
    zbd_close(read_direct_f_);
    zbd_close(write_f_);
  }

  IOStatus Open(bool readonly, bool exclusive, unsigned int *max_active_zones,
                unsigned int *max_open_zones);
  std::unique_ptr<ZoneList> ListZones();
  IOStatus Reset(uint64_t start, bool *offline, uint64_t *max_capacity);
  IOStatus Finish(uint64_t start);
  IOStatus Close(uint64_t start);
  int Read(char *buf, int size, uint64_t pos, bool direct);
  int Write(char *data, uint32_t size, uint64_t pos);
  int InvalidateCache(uint64_t pos, uint64_t size);

  bool ZoneIsSwr(std::unique_ptr<ZoneList> &zones, unsigned int idx) {

  };

  bool ZoneIsOffline(std::unique_ptr<ZoneList> &zones, unsigned int idx) {

  };

  bool ZoneIsWritable(std::unique_ptr<ZoneList> &zones, unsigned int idx) {

  };

  bool ZoneIsActive(std::unique_ptr<ZoneList> &zones, unsigned int idx) {

  };

  bool ZoneIsOpen(std::unique_ptr<ZoneList> &zones, unsigned int idx) {

  };

  uint64_t ZoneStart(std::unique_ptr<ZoneList> &zones, unsigned int idx) {

  };

  uint64_t ZoneMaxCapacity(std::unique_ptr<ZoneList> &zones, unsigned int idx) {

  };

  uint64_t ZoneWp(std::unique_ptr<ZoneList> &zones, unsigned int idx) {

  };

  std::string GetFilename() { return filename_; }

 private:
  IOStatus CheckScheduler();
  std::string ErrorToString(int err);
};

}  // namespace ROCKSDB_NAMESPACE

// #endif  // !defined(ROCKSDB_LITE) && defined(OS_LINUX)
