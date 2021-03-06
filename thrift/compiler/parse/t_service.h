/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef T_SERVICE_H
#define T_SERVICE_H

#include "thrift/compiler/parse/t_function.h"
#include <vector>

class t_program;

/**
 * A service consists of a set of functions.
 *
 */
class t_service : public t_type {
 public:
  explicit t_service(t_program* program) :
    t_type(program),
    extends_(nullptr) {}

  bool is_service() const {
    return true;
  }

  void set_extends(t_service* extends) {
    extends_ = extends;
  }

  void add_function(t_function* func) {
    functions_.push_back(func);
  }

  const std::vector<t_function*>& get_functions() const {
    return functions_;
  }

  t_service* get_extends() {
    return extends_;
  }

  virtual TypeValue get_type_value() const {
    return t_types::TYPE_SERVICE;
  }

  virtual std::string get_full_name() const {
    return make_full_name("service");
  }

  virtual std::string get_impl_full_name() const {
    return make_full_name("service");
  }

 private:
  std::vector<t_function*> functions_;
  t_service* extends_;
};

#endif
