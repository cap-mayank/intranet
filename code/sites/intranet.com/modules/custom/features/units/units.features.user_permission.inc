<?php
/**
 * @file
 * units.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function units_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create units content'.
  $permissions['create units content'] = array(
    'name' => 'create units content',
    'roles' => array(
      'administrator' => 'administrator',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any units content'.
  $permissions['delete any units content'] = array(
    'name' => 'delete any units content',
    'roles' => array(
      'administrator' => 'administrator',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own units content'.
  $permissions['delete own units content'] = array(
    'name' => 'delete own units content',
    'roles' => array(
      'administrator' => 'administrator',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any units content'.
  $permissions['edit any units content'] = array(
    'name' => 'edit any units content',
    'roles' => array(
      'administrator' => 'administrator',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own units content'.
  $permissions['edit own units content'] = array(
    'name' => 'edit own units content',
    'roles' => array(
      'administrator' => 'administrator',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
