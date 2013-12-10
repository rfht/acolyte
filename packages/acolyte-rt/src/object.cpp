// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "ert/real.hpp"
#include "ert/property.hpp"
#include "ert/object.hpp"
#include "ert/math.hpp"
#include "ert/vector.hpp"

namespace ert {
  namespace internal {
    decltype(event_schedule) event_schedule;
    decltype(object_map) object_map;
  }
  
  object::object(id_t id, real_t x, real_t y)
    : id(id), xstart(x), ystart(y), x(x), y(y), xprevious(x), yprevious(y) {
  }
  
  property_ro<object, object::id_t, &object::get_object_index> object::object_index() {
    return {this};
  }
  
  bool object::get_solid() {
    return this->properties.solid;
  }
  
  void object::set_solid(bool solid) {
    this->properties.solid = solid;
  }
  
  property<object, bool, &object::get_solid, &object::set_solid> object::solid() {
    return {this};
  }
  
  bool object::get_visible() {
    return this->properties.visible;
  }
  
  void object::set_visible(bool visible) {
    // TODO: link/unlink draw event from event chain
    this->properties.visible = visible;
  }
  
  property<object, bool, &object::get_visible, &object::set_visible> object::visible() {
    return {this};
  }
  
  bool object::get_persistent() {
    return this->properties.persistent;
  }
  
  void object::set_persistent(bool persistent) {
    this->properties.persistent = persistent;
  }
  property<object, bool, &object::get_persistent, &object::set_persistent> object::persistent() {
    return {this};
  }
  
  real_t object::get_depth() {
    return this->properties.depth;
  }
  
  void object::set_depth(real_t depth) {
    // TOOD: update objects event registrations
    this->properties.depth = depth;
  }
  
  property<object, real_t, &object::get_depth, &object::set_depth> object::depth() {
    return {this};
  }
  
  real_t object::get_sprite_index() {
    return this->properties.sprite_index;
  }
  
  void object::set_sprite_index(real_t sprite) {
    this->properties.sprite_index = sprite;
  }
  
  property<object, real_t, &object::get_sprite_index, &object::set_sprite_index> object::sprite_index() {
    return {this};
  }
  
  real_t object::get_sprite_width() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_sprite_width> object::sprite_width() {
    return {this};
  }
  
  real_t object::get_sprite_height() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_sprite_height> object::sprite_height() {
    return {this};
  }
  
  real_t object::get_sprite_xoffset() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_sprite_xoffset> object::sprite_xoffset() {
    return {this};
  }
  
  real_t object::get_sprite_yoffset() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_sprite_yoffset> object::sprite_yoffset() {
    return {this};
  }
  
  real_t object::get_image_alpha() {
    return this->properties.image_alpha;
  }
  
  void object::set_image_alpha(real_t alpha) {
    this->properties.image_alpha = alpha;
  }
  
  property<object, real_t, &object::get_image_alpha, &object::set_image_alpha> object::image_alpha() {
    return {this};
  }
  
  real_t object::get_image_angle() {
    return this->properties.image_angle;
  }
  
  void object::set_image_angle(real_t angle) {
    this->properties.image_angle = angle;
  }
  
  property<object, real_t, &object::get_image_angle, &object::set_image_angle> object::image_angle() {
    return {this};
  }
  
  real_t object::get_image_blend() {
    return this->properties.image_blend;
  }
  
  void object::set_image_blend(real_t blend) {
    this->properties.image_blend = blend;
  }
  
  property<object, real_t, &object::get_image_blend, &object::set_image_blend> object::image_blend() {
    return {this};
  }
  
  real_t object::get_image_index() {
    return this->properties.image_index;
  }
  
  void object::set_image_index(real_t index) {
    this->properties.image_index = index;
  }
  
  property<object, real_t, &object::get_image_index, &object::set_image_index> object::image_index() {
    return {this};
  }
  
  real_t object::get_image_number() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_image_number> object::image_number() {
    return {this};
  }
  
  real_t object::get_image_speed() {
    return this->properties.image_speed;
  }
  
  void object::set_image_speed(real_t speed) {
    this->properties.image_speed = speed;
  }
  
  property<object, real_t, &object::get_image_speed, &object::set_image_speed> object::image_speed() {
    return {this};
  }
  
  real_t object::get_image_xscale() {
    return this->properties.image_xscale;
  }
  
  void object::set_image_xscale(real_t xscale) {
    this->properties.image_xscale = xscale;
  }
  
  property<object, real_t, &object::get_image_xscale, &object::set_image_xscale> object::image_xscale() {
    return {this};
  }
  
  real_t object::get_image_yscale() {
    return this->properties.image_yscale;
  }
  
  void object::set_image_yscale(real_t yscale) {
    this->properties.image_yscale = yscale;
  }
  
  property<object, real_t, &object::get_image_yscale, &object::set_image_yscale> object::image_yscale() {
    return {this};
  }
  
  real_t object::get_mask_index() {
    return this->properties.mask_index;
  }
  
  void object::set_mask_index(real_t index) {
    this->properties.mask_index = index;
  }
  
  property<object, real_t, &object::get_mask_index, &object::set_mask_index> object::mask_index() {
    return {this};
  }
  
  real_t object::get_bbox_bottom() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_bbox_bottom> object::bbox_bottom() {
    return {this};
  }
  
  real_t object::get_bbox_left() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_bbox_left> object::bbox_left() {
    return {this};
  }
  
  real_t object::get_bbox_right() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_bbox_right> object::bbox_right() {
    return {this};
  }
  
  real_t object::get_bbox_top() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_bbox_top> object::bbox_top() {
    return {this};
  }
  
  real_t object::get_direction() {
    return this->properties.direction;
  }
  
  void object::set_direction(real_t direction) {
    this->properties.direction = direction;
    this->update_hspeed();
    this->update_vspeed();
    this->update_friction();
  }
  
  void object::update_direction() {
    this->properties.direction = internal::vector_direction_rad(this->properties.hspeed, this->properties.vspeed);
  }
  
  property<object, real_t, &object::get_direction, &object::set_direction> object::direction() {
    return {this};
  }
  
  real_t object::get_friction() {
    return this->properties.friction;
  }
  
  void object::set_friction(real_t friction) {
    this->properties.friction = friction;
    this->update_friction();
  }
  
  void object::update_friction() {
    this->properties.hfriction = this->properties.friction * std::cos(this->properties.direction);
    this->properties.vfriction = -this->properties.friction * std::sin(this->properties.direction);
  }
  
  property<object, real_t, &object::get_friction, &object::set_friction> object::friction() {
    return {this};
  }
  
  real_t object::get_gravity() {
    return this->properties.gravity;
  }
  
  void object::set_gravity(real_t gravity) {
    this->properties.gravity = gravity;
    this->update_gravity();
  }
  
  void object::update_gravity() {
    this->properties.hgravity = this->properties.gravity * std::cos(this->properties.gravity_direction);
    this->properties.vgravity = -this->properties.gravity * std::sin(this->properties.gravity_direction);
  }
  
  property<object, real_t, &object::get_gravity, &object::set_gravity> object::gravity() {
    return {this};
  }
  
  real_t object::get_gravity_direction() {
    return radtodeg(this->properties.gravity_direction);
  }
  
  void object::set_gravity_direction(real_t direction) {
    this->properties.gravity_direction = degtorad(direction);
    this->update_gravity();
  }
  
  property<object, real_t, &object::get_gravity_direction, &object::set_gravity_direction> object::gravity_direction() {
    return {this};
  }
  
  real_t object::get_hspeed() {
    return this->properties.hspeed;
  }
  
  void object::set_hspeed(real_t hspeed) {
    this->properties.hspeed = hspeed;
    this->update_speed();
    this->update_direction();
  }
  
  void object::update_hspeed() {
    this->properties.hspeed = this->properties.speed * std::cos(this->properties.direction);
  }
  
  property<object, real_t, &object::get_hspeed, &object::set_hspeed> object::hspeed() {
    return {this};
  }
  
  real_t object::get_vspeed() {
    return this->properties.vspeed;
  }
  
  void object::set_vspeed(real_t vspeed) {
    this->properties.vspeed = vspeed;
    this->update_speed();
    this->update_direction();
  }
  
  void object::update_vspeed() {
    this->properties.vspeed = -this->properties.speed * std::sin(this->properties.direction);
  }
  
  property<object, real_t, &object::get_vspeed, &object::set_vspeed> object::vspeed() {
    return {this};
  }
  
  real_t object::get_speed() {
    return this->properties.speed;
  }
  
  void object::set_speed(real_t speed) {
    this->properties.speed = speed;
    this->update_hspeed();
    this->update_vspeed();
  }
  
  void object::update_speed() {
    this->properties.speed = internal::vector_length(this->properties.hspeed, this->properties.vspeed);
  }
  
  property<object, real_t, &object::get_speed, &object::set_speed> object::speed() {
    return {this};
  }
}
