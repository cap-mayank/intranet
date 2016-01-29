<?php
/**
 * @file
 * anniversary.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function anniversary_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'user',
  );

  return $permissions;
}
