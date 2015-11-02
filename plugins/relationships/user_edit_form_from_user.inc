<?php

/**
 * @file
 * Plugin to provide an relationship handler 'edit form' for User.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('User edit form'),
  'keyword' => 'user_edit_form',
  'description' => t('Adds user edit form from a user context.'),
  'required context' => new ctools_context_required(t('User'), 'entity:user'),
  'context' => 'profile2_panels_user_edit_form_from_user_context',
);

/**
 * Return a new context based on an existing context.
 */
function profile2_panels_user_edit_form_from_user_context($context, $conf) {

  // Probably a new user form.
  // TODO: Anything else to consider?
  if (empty($context->data)) {
    return ctools_context_create_empty('user_edit_form', NULL);
  }

  // Load the user edit for form for availabel user context.
  if (isset($context->data->uid)) {
    return ctools_context_create('user_edit_form', $context->data);
  }
}
